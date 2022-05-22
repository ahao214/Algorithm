using namespace std;


class Solution {
	/*
	50. Pow(x, n)
	ʵ�� pow(x, n) �������� x �� n ���ݺ���������x^n ����
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