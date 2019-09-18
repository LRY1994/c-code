// battery model section
// all parameters are here
#include <iostream>
#include <vector>
#include "Lookuptable.h"
#include "rtwtypes.h"
using namespace std;


const double Tenv = -10;
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

static LookuptableModelClass *rtObj= new  LookuptableModelClass();

vector<double> dt;

// Input I algorithm（还没完成）
double getI(){
    return 37;
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

//Qt(还没完成)
double getQt(double I,double Tnex){
    double Beta = I/37;
    rtObj->initialize();
    rtObj->rtU.Tnex = Tnex;
    rtObj->rtU.Beta = Beta;
    rtObj->step();
    double Qt = rtObj->rtY.Qt;
    return Qt;
    //  }


}

//DeltaSOC 
double getDsoc(double I,double Pptc,double Tnex,int layer){
    double Qt = getQt(I,Tnex);
    return (I+Pptc/Uptc)*(dt[layer-1]/3600)/Qt;
}

//R0（还没完成）
double SOC = SOC0;
double getR(double T,double I,double Pptc,int layer){
    SOC = SOC - getDsoc(I,Pptc,T,layer);
    rtObj->rtU.T = T;
    rtObj->rtU.SOC = SOC;
    rtObj->step();
    double R0 = rtObj->rtY.Qt;
    return R0;
}

//cooling power
double getPcool(double T,double Tnex) {
    return ((Tnex+T)/2-Tenv)/(deltax/(lamda*A)+1/(ha*A));
}

//exo power
double getPexo(double T,double I,double Pptc,int layer) {
    double R = getR(T,I,Pptc,layer);
    return I*I*R;
}

//delta temperature
double getdeltaT(double Pptc,double Pcool,double Pexo,double time) {
    return (Pptc-Pcool+Pexo)*time/Ctotal;
}

//PTC power
double getPptc(double T,double Tnex,double Pcool,double Pexo,double time) { 
    return (Tnex-T)*Ctotal/time+Pcool-Pexo;
}


double get_highest_temp(double T,int layer,double I)
{  
    double Pptc = Pmax;
    double Pcool = getPcool(T,T);
    double Pexo = getPexo(T,I,Pptc,layer);
    return getdeltaT(Pptc,Pcool,Pexo,dt[layer-1]) + T;

}

double get_lowest_temp(double T,int layer,double I)
{
    double Pptc = 0;
    double Pcool = getPcool(T,T);
    double Pexo = getPexo(T,I,Pptc,layer);
    return getdeltaT(Pptc,Pcool,Pexo,dt[layer-1]) + T;
}

double get_firstLayer_temp(int i,double parent,int N,int layer,double I){
    double Tmin = get_lowest_temp(parent,layer,I);
    double Tmax = get_highest_temp(parent,layer,I);

    return (2*N-2*i+1)*Tmin/(2*N)+(2*i-1)*Tmax/(2*N);
   
}

//T is parent,Tnex is child
double cal_power(double parent,double child,int layer,double I)
{
    // double Tmin = get_lowest_temp(parent,layer,I);
    // double Tmax = get_highest_temp(parent,layer,I);
    double Qt = getQt(I,child);
    double Pcool = getPcool(parent,child);
    double Pexo = getPexo(parent,I,0,layer);
    double Pptc = getPptc(parent,child,Pcool,Pexo,dt[layer-1]);
    return (Pptc/48+I) * (Q0/Qt) * (dt[layer-1]/3600);

}

