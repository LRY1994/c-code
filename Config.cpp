// battery model section
// all parameters are here
#include <iostream>
#include <vector>
#include "Lookuptable.h"
#include "rtwtypes.h"
using namespace std;


const double Tenv = -30;
const double E = 0;
const double deltax = 0.01;
const double lamda = 0.03;
const double ha = 7.5;
const double A = 0.54;
const double Pmax = 500;
const double Q0 = 37;
const double Ctotal = 19501.272;
const double SOC0 = 1;
const double Uptc = 48;
const double Pptc0 =0;

static LookuptableModelClass *rtObj= new  LookuptableModelClass();

vector<double> dt;

// Input I algorithm（还没完成）
double getI(){
    return 10;
}

// adaptive dt algorithm（可选）
void getDt(int segment,double I){
    for(int i=0;i<segment;i++){
        dt.push_back(10);
    }
}

double getTime(double lastTime,int layer){
    return lastTime + dt[layer-1];
}

//Qt
double getQt(double I,double T){
    double Beta = I/37;
    rtObj->initialize();
    rtObj->rtU.Tnex = T;
    rtObj->rtU.Beta = Beta;
    rtObj->step();
    double Qtt = 0.37*(rtObj->rtY.Qt);
    return Qtt;
}



//R0
double getR(double T,double I,double SOC,int layer){
    rtObj->initialize();
    rtObj->rtU.T = T;
    rtObj->rtU.SOC = SOC;
    rtObj->step();
    double R0 = rtObj->rtY.R0;
    printf("R0:%lf\n\n",R0);
    return R0;
}

//cooling power
double getPcool(double T,double Tnex) {
    return ((Tnex+T)/2-Tenv)/(deltax/(lamda*A)+1/(ha*A));
}

//exo power
double getPexo(double T,double I,double SOC,int layer) {
    double R0 = getR(T,I,SOC,layer);
    return I*I*R0;
}

//delta temperature
double getdeltaT(double Pptc,double Pcool,double Pexo,int layer) {
    return (Pptc-Pcool+Pexo)*dt[layer-1]/Ctotal;
}

//PTC power
double getPptc(double T,double Tnex,double Pcool,double Pexo,int layer) {
    double getPptc = (Tnex-T)*Ctotal/dt[layer-1]+Pcool-Pexo;
    if (getPptc < 0){
        return 0;
    }    
    else if (getPptc > 500){
        return 500;
    } 
    return getPptc;     
}

//DeltaSOC 
double getSoc(double parentT, double childT, double parentSOC,double I,int parentLayer){
    double Pcool = getPcool(parentT,childT);
    double Pexo = getPexo(parentT,I,parentSOC,parentLayer);
    double Pptc = getPptc(parentT,childT,Pcool,Pexo,parentLayer); 
    double Qt = getQt(I,childT);
    double dsoc = (I+Pptc/Uptc)*(dt[parentLayer-1]/3600)/Qt;
    return parentSOC - dsoc;
}
double get_highest_temp(double T,int layer,double I,double SOC)
{  
    double Pptc = Pmax;
    double Pcool = getPcool(T,T);
    double Pexo = getPexo(T,I,SOC,layer);
    return getdeltaT(Pptc,Pcool,Pexo,layer) + T;

}

double get_lowest_temp(double T,int layer,double I,double SOC)
{
    double Pptc = 0;
    double Pcool = getPcool(T,T);
    double Pexo = getPexo(T,I,SOC,layer);
    return getdeltaT(Pptc,Pcool,Pexo,layer) + T;
}
/**
* define first layer temperature
* i :index of childNodes,begin with 0
* N :number of first layer nodes
* parentT :the temperature of parent 
* 
*/
double get_firstLayer_temp(int i,int N,double parentT,double I,double SOC){
   
  
    const int layer = 1;
    double Tmin = get_lowest_temp(parentT,layer,I,SOC);
    double Tmax = get_highest_temp(parentT,layer,I,SOC);
    double const M = 2*N;
    double childT = ( M - 2 * i + 1) * Tmin/ M  + (2 * i - 1) * Tmax/ M ;

    printf("parentT:%lf\n",parentT);
    printf("childTmin:%lf\n",Tmin);
    printf("childTmax:%lf\n",Tmax);
    printf("childT:%lf\n\n",childT);
 
    return childT;
   
}
/**
* parentT :parent's temperature
* childT:child's temperature
* layer: parent's layer,begin with 1
*/
//T is parent,Tnex is child
double Pptc =Pptc0;
double cal_power(double parent,double child,int layer,double I,double SOC)
{
    // double Tmin = get_lowest_temp(parent,layer,I);
    // double Tmax = get_highest_temp(parent,layer,I);
    double Qt = getQt(I,child);
    double Pcool = getPcool(parent,child);
    double Pexo = getPexo(parent,I, SOC,layer);
    double Pptc = getPptc(parent,child,Pcool,Pexo,layer);
    printf("Qt:%.4lf; Pcool:%.4lf; Pexo:%.4lf; Pptc:%.4lf; layer:%ld\n",Qt, Pcool, Pexo, Pptc,layer);
    return (Pptc/Uptc+I) * (Q0/Qt) * (dt[layer-1]/3600);

}

