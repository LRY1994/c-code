// battery model section
// all parameters are here
#include <iostream>
using namespace std;


double Tenv = -10;
double E = 0;
double I = 1;
double deltax = 0.1;
double lamda = 0.1;
double ha = 0.1;
double A = 1;
double R = 1;
double Pmax = 500;
double Qt = 30;
double Q0 = 37;
double Ctotal = 100;
double time = 1;
// double Pcool;
// double Pexo; 
// double Pptc;
// double deltaT;

//散热功率
double getPcool(double T,double Tnex) {
    return ((Tnex+T)/2-Tenv)/(deltax/(lamda*A)+1/(ha*A));
}
//发热功率
double getPexo() {
    return I*I*R;
}
//温度变化量
double getdeltaT(double Pptc,double Pcool,double Pexo) {
    return (Pptc-Pcool+Pexo)*time/Ctotal;
}
//加热功率
double getPptc(double T,double Tnex,double Pcool,double Pexo) { 
    return (Tnex-T)*Ctotal/time+Pcool-Pexo;
}


double get_highest_temp(double T)
{  
    double Pcool = getPcool(T,T);
    double Pexo = getPexo();
    double Pptc = Pmax;
    return getdeltaT(Pptc,Pcool,Pexo) + T;

}

double get_lowest_temp(double T)
{
    double Pcool = getPcool(T,T);
    double Pexo = getPexo();
    double Pptc = 0;
    return getdeltaT(Pptc,Pcool,Pexo) + T;
}

double get_firstLayer_temp(int n,double parent,int N){
    double Tmin = get_lowest_temp(parent);
    double Tmax = get_highest_temp(parent);

    return (2*n+1)/2*N*Tmin+(2*N-2*n-1)/2*N*Tmax;
   
}

double cal_power(double parent, double child)
{
    double Tmin = get_lowest_temp(parent);
    double Tmax = get_highest_temp(parent);
    double Pcool = getPcool(parent,child);
    double Pexo = getPexo();
    double Pptc = getPptc(parent,child,Pcool,Pexo);
//        cout<<Tmin<<endl;
//          cout<<Tmax<<endl;
//            cout<<Pcool<<endl;
//              cout<<Pexo<<endl;
//                cout<<Pptc<<endl;
// cout<<(Pptc/48+I)*Qt/Q0*time<<endl;
//                cout<<endl;

    return (Pptc/48+I)*Qt/Q0*time;

}