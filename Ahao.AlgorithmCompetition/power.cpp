/*
现在已经知道X和n，试计算X^n的值

输入格式：
X = 3 n = 2
输出格式：
9

*/


//基本快速幂运算
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


//位优化快速幂运算
long long Pow(long long x, long long n) {
	long long result;
	if (n == 0) {
		return 1;
	}
	else {
		while ((n & 1) = 0) {		//当n为偶数时
			n >>= 1;		//即n = n / 2;
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








