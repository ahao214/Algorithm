/*
�����Ѿ�֪��X��n���Լ���X^n��ֵ

�����ʽ��
X = 3 n = 2
�����ʽ��
9

*/


//��������������
#include<cstdint>
#include<cstdlib>
#include<iostream>
using namespace std;


int pow(int a, int b) {
	if (b == 1) {
		return a;
	}
	else {
		int c = pow(a, b / 2);
		if ((b % 2) == 0) {
			return c * c;
		}
		else {
			return c * c * a;
		}
	}
}

int main() {
	int X, n;
	cin >> X >> n;
	cout << pow(X, n) << endl;
	return 0;
}