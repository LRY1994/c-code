// battery model section
// all parameters are here
#include <iostream>
#include<vector>
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

//Qt
double getQt(double I,double Tnex){
    double Beta = I/37;
     return 0.37*(
         89.4 + 
         -3.163 * Beta + 
         8.68   * Tnex + 
         2.17   * Beta * Beta + 
         8.639  * Beta * Tnex + 
         -8.732 * Tnex * Tnex+ 
         0.2467 * Beta * Beta * Beta + 
         
         0.002463 * Beta * Beta * Tnex + 
         -11.48   * Beta * Tnex * Tnex + 
         13.26    * Tnex * Tnex * Tnex + 
         -1.727   * Beta * Beta * Beta * Beta + 
         
         -1.372  * Beta * Beta * Beta * Tnex + 
         -0.5792 * Beta * Beta * Tnex * Tnex + 
         0.09279 * Beta * Tnex * Tnex * Tnex + 
         -1.282  * Tnex * Tnex * Tnex * Tnex + 
         
         1.096   * Beta * Beta * Beta * Beta * Tnex + 
         0.9156  * Beta * Beta * Beta * Tnex * Tnex + 
         -0.3832 * Beta * Beta * Tnex * Tnex * Tnex + 
         
         2.404  * Beta * Tnex * Tnex * Tnex * Tnex + 
         -3.912 * Tnex * Tnex * Tnex * Tnex * Tnex
         );
}

//SOC 
double getDsoc(double I,double Pptc,double Tnex){
    double Qt = getQt(I,Tnex);
    return (I+Pptc/Uptc)/Qt*(dt[1]/3600);
}

//R0
double SOC = SOC0;
double getR(double T,double I,double Pptc){
    SOC = SOC - getDsoc(I,Pptc,T);
    return (5.92910+0.03751*T-13.36710*SOC+16.52510*SOC*SOC-6.23355*SOC*SOC*SOC)/
    (1+0.06745*T+9.76290*0.0001*T*T-3.41128*0.00001*T*T*T-0.48719*SOC+0.34875*SOC*SOC);
}

//cooling power
double getPcool(double T,double Tnex) {
    return ((Tnex+T)/2-Tenv)/(deltax/(lamda*A)+1/(ha*A));
}

//exo power
double getPexo(double T,double I,double Pptc) {
    double R = getR(T,I,Pptc);
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
    double Pexo = getPexo(T,I,Pptc);
    return getdeltaT(Pptc,Pcool,Pexo,dt[layer-1]) + T;

}

double get_lowest_temp(double T,int layer,double I)
{
    double Pptc = 0;
    double Pcool = getPcool(T,T);
    double Pexo = getPexo(T,I,Pptc);
    return getdeltaT(Pptc,Pcool,Pexo,dt[layer-1]) + T;
}
/**
* define first layer temperature
* i :index of childNodes
* N :number of first layer nodes
* parentT :the temperature of parent 
* 
*/
double get_firstLayer_temp(int i,int N,double parentT,double I){
    const int layer = 1;
    double Tmin = get_lowest_temp(parentT,layer,I);
    double Tmax = get_highest_temp(parentT,layer,I);
    double const M = 2*N;
    double childT = ( M - 2 * i + 1) * Tmin/ M  + (2 * i - 1) * Tmax/ M ;

    // printf("parentT:%lf\n",parentT);
    // printf("childTmin:%lf\n",Tmin);
    // printf("childTmax:%lf\n",Tmax);
    // printf("childT:%lf\n",childT);
 
    return childT;
   
}
/**
* parentT :parent's temperature
* childT:child's temperature
* layer: parent's layer,begin with 1
*/
//T is parent,Tnex is child
double cal_power(double parent,double child,int layer,double I)
{
    // double Tmin = get_lowest_temp(parent,layer,I);
    // double Tmax = get_highest_temp(parent,layer,I);
    double Qt = getQt(I,child);
    double Pcool = getPcool(parent,child);
    double Pexo = getPexo(parent,I,0);
    double Pptc = getPptc(parent,child,Pcool,Pexo,dt[layer-1]);
    printf("Qt:%.4lf; Pcool:%.4lf; Pexo:%.4lf; Pptc:%.4lf; layer:%ld\n",Qt, Pcool, Pexo, Pptc,layer);
    return (Pptc/48+I) * (Q0/Qt) * (dt[layer-1]/3600);

}

