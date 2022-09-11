/*
输入格式：四个实数即a、b、c、d
输出格式：为排好序的三个实根

输入样例：1 -5 -4 20
输出样例：-2.00 2.00 5.00

*/


//解一元三次方程——枚举法
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

int main() {
	double a, b, c, d, x, fx;
	int i;

	cin >> a >> b >> c >> d;
	cout.precision(2);		//设置精度 即小数点位数
	cout.setf(ios::fixed);	//以定点形式显示浮点数

	for (i = -10000; i <= 10000; i = (++i) / 100.0)
	{
		fx = a * x * x * x + b * x * x + c * c + d;
		if (fx >= -0.01 && fx <= 0.01)
		{
			cout << x << ' ';
		}
	}
	cout << '\n';
	return 0;
}