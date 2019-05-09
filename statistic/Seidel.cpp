//Seidel算法
#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
double a[1000][1000];
double b[1000];
double Y[1000],X[1000];
double g[1000];
int main(){
	int n;
	printf("请输入n\n");
	scanf("%d",&n);

	printf("请输入A矩阵\n");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%lf",&a[i][j]);
		}
	}
	printf("请输入b矩阵\n");
	for(int i=1;i<=n;i++)
		scanf("%lf",&b[i]);

	for(int i=1;i<=n;i++)Y[i]=0;

	double e;
	printf("请输入允许误差\n");
	scanf("%lf",&e);

	int M;
	printf("请输入最大迭代次数\n");
	scanf("%d",&M);

	int k=1;
	double T;
	int fail=0;
	for(int i=1;i<=n;i++)
	{
		if(fabs(a[i][i])<e){
			printf("求解失败\n");
			fail=1;
			break;
		}
		else {
			T=a[i][i];
			for(int j=1;j<=n;j++)
			{
				a[i][j]=-a[i][j]/T;
				a[i][i]=0;
				g[i]=b[i]/T;
			}
		}
	}
	if(fail) return 0;


	while(1){
	double sum;
	for(int i=1;i<=n;i++){
		sum=0;
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			sum+=a[i][j]*X[j];
		}
		X[i]=g[i]+sum;
	}
	sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=(X[i]-Y[i])*(X[i]-Y[i]);
	}
	if(sum<e*e){
		for(int i=1;i<=n;i++)printf("%lf ",X[i]);
		printf("\nk=%d\n",k);
		break;
	}
	else {
		if(k<M) {
			k++;
			for(int i=1;i<=n;i++)Y[i]=X[i];
		}
		else{
			printf("求解失败\n");
			fail=1;
			break;
		}
	}
}
	
}
