using namespace std;


class Solution {
	/*
	50. Pow(x, n)
	实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，x^n ）。
	*/
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