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


//λ�Ż�����������
long long Pow(long long x, long long n) {
	long long result;
	if (n == 0) {
		return 1;
	}
	else {
		while ((n & 1) = 0) {		//��nΪż��ʱ
			n >>= 1;		//��n = n / 2;
			x *= x;
		}
	}
	result = x;
	n >>= 1;
	while (n != 0) {
		x *= x;
		if ((n & 1) != 0) {
			result *= x;
		}
		n >>= 1;
	}
	return result;
}

int main() {
	long long x, n;
	cin >> x >> n;
	cout << Pow(x, n) << endl;
	return 0;
}








