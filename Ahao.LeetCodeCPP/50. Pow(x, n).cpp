using namespace std;



/*
50. Pow(x, n)
实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，x^n ）。
*/
class Solution {
public:
	double myPow(double x, int n) {
		long long N = n;
		if (n < 0) N = -N;
		double ans = 1.0;
		while (N)
		{
			if (N & 1) ans *= x;
			x *= x;
			N >>= 1;
		}
		return n < 0 ? 1 / ans : ans;
	}
};



class Solution {
	double pow(double x, long n) {
		if (n == 0) {
			return 1;
		}
		double half = pow(x, n / 2);
		if (n % 2 == 0) {
			return half * half;
		}
		else
		{
			return half * half * x;
		}
	}

public:
	double myPow(double x, int n) {
		if (x == 0 || x == 1) {
			return x;
		}
		if (n >= 0) {
			return pow(x, n);
		}
		else
		{
			return 1 / pow(x, (long)n * (-1));
		}
	}
};
