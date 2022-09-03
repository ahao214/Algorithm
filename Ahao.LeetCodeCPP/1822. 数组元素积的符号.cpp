#include<vector>
using namespace std;



/*
1822. 数组元素积的符号
已知函数 signFunc(x) 将会根据 x 的正负返回特定值：

如果 x 是正数，返回 1 。
如果 x 是负数，返回 -1 。
如果 x 是等于 0 ，返回 0 。
给你一个整数数组 nums 。令 product 为数组 nums 中所有元素值的乘积。

返回 signFunc(product) 。
*/
class Solution {
public:
	int sign(int x)
	{
		if (x > 0) return 1;
		if (x < 0) return -1;
		return 0;
	}

	int arraySign(vector<int>& nums) {
		int res = 1;
		for (auto x : nums)
			res *= sign(x);
		return res;
	}
};