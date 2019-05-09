//Romberg求积法
#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

double T[1000][1000];
double f(double x){
	return sqrt(x);
}
long long power(int x,int c){
	long long s=1;
	for(int i=1;i<=c;i++)
		s=s*x;
	return s;
}

int main(){
	int a,b;
	double e;
	
    printf("请输入a:");
	scanf("%d",&a);
	printf("请输入b:");
	scanf("%d",&b);
	printf("请输入e:");
	scanf("%lf",&e);

	T[0][0]=(b-a)*(f(a)+f(b))/2;
	int k=1;
	double sum;
	long long count,t;

	while(1){
	count=power(2,k-1);
	sum=0;
	for(int i=1;i<=count;i++)
	{
		sum+=f(double((2*i-1)*(b-a))/(count*2)+a);
		
	}
	T[0][k]=(T[0][k-1]+double(b-a)/count*sum)/2;
	
	for(int m=1;m<=k;m++)
	{
		t=power(4,m);
		T[m][k-m]=(t*T[m-1][k-m+1]-T[m-1][k-m])/(t-1);
	}
	if(fabs(T[k][0]-T[k-1][0])<e){
		printf("%lf\n",T[k][0]);
		break;
	}
	else k++;
	}
}
