using namespace std;

/*
69. x 的平方根
给你一个非负整数 x ，计算并返回 x 的 算术平方根 。

由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。

注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。
*/
class Solution {
public:
	/*
	Times:O(logN)
	Space:O(1)
	二分
	*/
	int mySqrt(int x) {
		int left = 0, right = x;
		while (left < right)
		{
			int mid = left + (right - left) / 2 + 1;
			if ((long long)mid * mid <= x)
				left = mid;
			else
				right = mid - 1;
		}
		return left;
	}
};


/*
69. x 的平方根
给你一个非负整数 x ，计算并返回x的算术平方根 。

由于返回类型是整数，结果只保留整数部分 ，小数部分将被 舍去 。

注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。
*/
class Solution {
public:
	int mySqrt(int x) {
		int left = 0, right = x;
		while (left < right)
		{
			long long mid = left + 1ll + right >> 1;
			if (mid * mid <= x)
				left = mid;
			else
				right = mid - 1;
		}
		return left;
	}
};
