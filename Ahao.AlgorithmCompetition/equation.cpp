/*
�����ʽ���ĸ�ʵ����a��b��c��d
�����ʽ��Ϊ�ź��������ʵ��

����������1 -5 -4 20
���������-2.00 2.00 5.00

*/


//��һԪ���η��̡���ö�ٷ�
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

int main() {
	double a, b, c, d, x, fx;
	int i;

	cin >> a >> b >> c >> d;
	cout.precision(2);		//���þ��� ��С����λ��
	cout.setf(ios::fixed);	//�Զ�����ʽ��ʾ������

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