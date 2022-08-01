#include<vector>

using namespace std;



/*
offer 16 数值的整数次方
*/
class Solution {
public:
	double Power(double base, int exponent) {
		if (exponent == 0)
			return 1;
		if (exponent == 1)
			return base;
		double res = 1.0;
		if (exponent > 0)
		{
			for (int i = 0; i < exponent; ++i)
			{
				res *= base;
			}
		}
		else
		{
			exponent = -exponent;
			for (int i = 0; i < exponent; ++i)
			{
				res *= base;
			}
			res = 1.0 / res;
		}
		return res;

	}
};
