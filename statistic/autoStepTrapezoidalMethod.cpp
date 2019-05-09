//????????????¦Ç?
#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

double f(double x){
	return 2/(1+x*x);
}
int main(){
	int a,b;
	double e;
	int n;
	double T0,T1,S,t,h;
    printf("??????a:");
	scanf("%d",&a);
	printf("??????b:");
	scanf("%d",&b);
	printf("??????e:");
	scanf("%lf",&e);

	h=double(a-b)/2;
	T1=(f(a)+f(b))*h;
	n=1;

	while(1){
	T0=T1,S=0;
	for(int k=1;k<=n;k++){
		t=a+(2*k-1)*h/n;
	    S+=f(t);
	}
	T1=T0/2+S*h/n;
	if(fabs(T1-T0)<3*e) {
		printf("%lf\n",T1);
		break;
	}
	else n=2*n;
	
	}
	
}
