//列主元LU算法
#pragma warning(disable:4996)
#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
double a[1000][1000];
double b[1000];
double l[1000][1000];
double u[1000][1000];
double s[1000];
double y[1000];
double x[1000];
int main(){
	int n;
	printf("请输入n\n");
	scanf("%d", &n);

	printf("请输入A矩阵\n");
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			scanf("%lf", &a[i][j]);
		}
	}
	printf("请输入b矩阵\n");
	for (int i = 1; i <= n; i++)
		scanf("%lf", &b[i]);
	/*
	1 2 1
	2 2 3
	-1 -3 0
	*/


	double e;
	printf("请输入允许误差:");
	scanf("%lf", &e);

	for (int j = 1; j <= n; j++) { u[1][j] = a[1][j]; }
	l[1][1] = 1;
	for (int i = 2; i <= n; i++){ l[i][1] = a[i][1] / u[1][1]; l[i][i] = 1; }
	

	double sum;
	double temp;
	int fail;
	int ik;
	double zhuyuan;

	for (int k = 1; k <= n; k++){
		sum = 0;
		zhuyuan = 0;
		fail = 0;
		for (int i = k; i <= n; i++){
			for (int m = 1; m < k; m++)
			{
				sum += l[i][m] * u[m][k];
			}
			s[i] = a[i][k] - sum;
			if (fabs(zhuyuan) < fabs(s[i])){
				zhuyuan = s[i];
				ik = i;
			}
		}


		if (fabs(zhuyuan) < e){
			printf("求解失败");
			fail = 1;
			break;
		}
		else {
			//交换A的第k行和第ik行
			for (int j = 1; j <= n; j++){
				temp = a[k][j];
				a[k][j] = a[ik][j];
				a[ik][j] = temp;
			}
			//计算U的第k行元素
			for (int j = k; j <= n; j++){
				sum = 0;
				for (int m = 1; m < k; m++)
					sum += l[k][m] * u[m][j];
				u[k][j] = a[k][j] - sum;
			}
			//计算L的第k列元素
			for (int i = k + 1; i <= n; i++){
				sum = 0;
				for (int m = 1; m < k; m++)
					sum += l[i][m] * u[m][k];
				l[i][k] = (a[i][k] - sum) / u[k][k];
			}



			//将b向量的第k个元素和第ik个元素交换
			for (int j = 1; j <= n; j++){
				temp = b[k];
				b[k] = b[ik];
				b[ik] = temp;
			}
		}
	}


	if (!fail){

		//求解LY=b
		y[1] = b[1];
		for (int i = 2; i <= n; i++){
			sum = 0;
			for (int j = 1; j <= i - 1; j++){
				sum += l[i][j] * y[j];
			}
			y[i] = b[i] - sum;
		}
		//求解UX=Y
		x[n] = y[n] /u[n][n];
		for (int i = n - 1; i >= 1; i--){
			sum = 0;
			for (int j = i + 1; j <= n; j++){
				sum += u[i][j] * x[j];
			}
			x[i] = (y[i] - sum) / u[i][i];
		}
		//打印X
		printf("X的解为：");
		for (int i = 1; i <= n; i++)printf("%lf ", x[i]);
	}
}