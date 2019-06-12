// battery model section
// all parameters are here
#include <iostream>
#include<vector>
using namespace std;


const double  Tenv = -10;
const double E = 0;
const double I = 1;
const double deltax = 0.1;
const double lamda = 0.1;
const double ha = 0.1;
const double A = 1;
const double R = 1;
const double Pmax = 500;
const double Qt = 30;
const double Q0 = 37;
const double Ctotal = 100;


vector<double> dt;


//cooling power
double getPcool(double T,double Tnex) {
    return ((Tnex+T)/2-Tenv)/(deltax/(lamda*A)+1/(ha*A));
}
//exo power
double getPexo() {
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


double get_highest_temp(double T,int layer)
{  
    double Pcool = getPcool(T,T);
    double Pexo = getPexo();
    double Pptc = Pmax;
    return getdeltaT(Pptc,Pcool,Pexo,dt[layer-1]) + T;

}

double get_lowest_temp(double T,int layer)
{
    double Pcool = getPcool(T,T);
    double Pexo = getPexo();
    double Pptc = 0;
    return getdeltaT(Pptc,Pcool,Pexo,dt[layer-1]) + T;
}

double get_firstLayer_temp(int n,double parent,int N,int layer){
    double Tmin = get_lowest_temp(parent,layer);
    double Tmax = get_highest_temp(parent,layer);

    return (2*n+1)/2*N*Tmin+(2*N-2*n-1)/2*N*Tmax;
   
}

double cal_power(double parent, double child,int layer)
{
    double Tmin = get_lowest_temp(parent,layer);
    double Tmax = get_highest_temp(parent,layer);
    double Pcool = getPcool(parent,child);
    double Pexo = getPexo();
    double Pptc = getPptc(parent,child,Pcool,Pexo,dt[layer-1]);
    return (Pptc/48+I)*Qt/Q0*dt[layer-1];

}

double getTime(double lastTime,int layer){
    return lastTime + dt[layer-1];
}

void getDt(int segment){
    for(int i=0;i<segment;i++){
        dt.push_back(1);
    }
}