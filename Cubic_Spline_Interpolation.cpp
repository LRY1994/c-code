
//三次样条插值

#pragma warning(disable:4996)
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int x[1000000], y[1000000];
double afa[1000000], bta[1000000];
int  h[1000000];
double a[1000000], b[1000000];
double m[1000000];
void interpolation(){
	int n;
	int xx;
	printf("请输入n\n");
	scanf("%d", &n);
	printf("输入x\n");
	for (int i = 0; i <= n; i++) {
		scanf("%d", &x[i]);

	}
	for (int i = 0; i<n; i++)h[i] = x[i + 1] - x[i];//cout<<h[i]<<endl;

	printf("输入y\n");
	for (int i = 0; i <= n; i++) scanf("%d", &y[i]);
	printf("输入求值点xx\n");
	scanf("%d", &xx);
	printf("第一种边界条件选择1，第二种边界条件选择2:");
	int op;
	scanf("%d", &op);

	if (op == 1){
		printf("输入m[0],m[n]:");
		scanf("%lf%lf", &m[0], &m[n]);

		afa[0] = 0, bta[0] = 2 * m[0];
		afa[n] = 1, bta[n] = 2 * m[n];
	}
	if (op == 2){
		afa[0] = 1, bta[0] = 3 * double(y[1] - y[0]) / (h[0]);
		afa[n] = 0, bta[n] = 3 * double(y[n] - y[n - 1]) / (h[n - 1]);
	}

	for (int i = 1; i<n; i++)
	{
		afa[i] = double(h[i - 1]) / double(h[i - 1] + h[i]);
		bta[i] = 3 * ((1 - afa[i])*double(y[i] - y[i - 1]) / double(h[i - 1]) + afa[i] * double(y[i + 1] - y[i]) / double(h[i]));
	}
	a[0] = -afa[0] / 2; b[0] = bta[0] / 2;
	for (int i = 1; i<n + 1; i++)
	{
		double temp = 2 + (1 - afa[i])*a[i - 1];
		a[i] = -afa[i] / temp;
		b[i] = (bta[i] - (1 - afa[i])*b[i - 1]) / temp;
	}
	m[n + 1] = 0;
	for (int i = n; i >= 0; i--)
	{
		m[i] = a[i] * m[i + 1] + b[i];
		printf("解得m%d=%lf\n", i, m[i]);
	}

	int from, to;
	for (int i = 0; i <= n; i++){
		if (i == 0 && xx <= x[i + 1] && xx >= x[i]){
			from = i; to = i + 1;
			break;
		}
		if (i>0 && xx <= x[i + 1] && xx>x[i]){
			from = i; to = i + 1;
			break;
		}
	}
	
	double a1 = double(xx - x[from]) / double(x[to] - x[from]);
	double a2 = double(xx - x[to]) / double(x[from] - x[to]);
	double b1 = a1*a1;
	double b2 = a2*a2;
	double result = (1 + 2 * a1)*b2*y[from] + (1 + 2 * a2)*b1*y[to] + (xx - x[from])*b2*m[from] + (xx - x[to])*b1*m[to];

	printf("f(%d) is %lf\n", xx, result);
	// return 0;
}
