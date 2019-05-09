
//列主元高斯消去法

#pragma warning(disable:4996)
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

using namespace std;
double a[1000][1000];
double b[1000];
double x[1000];
int main()
{
	int n;
	printf("输入n\n");
	scanf("%d", &n);
	printf("输入A矩阵\n");
	for (int i =1; i<=n; i++){
		for (int j = 1; j<=n; j++){
			scanf("%lf", &a[i][j]);
		}
	}
	printf("输入B矩阵\n");
	for (int i =1; i<=n; i++)scanf("%lf", &b[i]);
	
	double  e;
	printf("输入允许误差：");
	scanf("%lf", &e);

	double zhuyuan ;
	int ik;
	double T, t;
	int flag ;
	for (int k = 1; k<n; k++)
	{
		zhuyuan = 0;
		flag = 1;
		//找到绝对值最大的作为主元
		for (int i = k; i <= n; i++){
			if (zhuyuan<abs(a[i][k])){
				zhuyuan = abs(a[i][k]);
				ik = i;
				
			}
		}
		
		if (zhuyuan < e){
			flag = 0;
			printf("求解失败\n");
			break;
		}
		//exchange two rows
		if (ik != k){
			for (int j = 1; j<=n; j++){
				t = a[k][j];
				a[k][j] = a[ik][j];
				a[ik][j] = t;
			}
			//exchange bik and bk
			t = b[ik];
			b[ik] = b[k];
			b[k] = t;
		}
		//消元
		for (int i = k + 1; i <= n; i++){
			T = a[i][k] / a[k][k];
			b[i] = b[i] -T*b[k];
			for (int j = k + 1; j <= n; j++){
				a[i][j] = a[i][j] - T*a[k][j];
			}
		}
	}
	if (!flag) return 0;

	//回代
	flag = 1;
	if (abs(a[n][n]) <= e) {
		printf("求解失败\n");
		return 0;
	}
	x[n] = b[n] / a[n][n];
	double sum;
	for (int i = n - 1; i >= 1; i--){
		sum = 0;
		for (int j = i + 1; j <= n; j++){
			sum += a[i][j] * x[j];
		}
		x[i] = (b[i] - sum) / a[i][i];
	}


	for (int i = 1; i<=n; i++){
		printf("x[%d] is %lf\n", i, x[i]);
	}
	return 0;
}


