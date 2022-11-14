#include<vector>

using namespace std;


/*
1567. 乘积为正数的最长子数组长度
给你一个整数数组 nums ，请你求出乘积为正数的最长子数组的长度。

一个数组的子数组是由原数组中零个或者更多个连续数字组成的数组。

请你返回乘积为正数的最长子数组长度。
*/
class Solution {
public:
	int getMaxLen(vector<int>& nums) {
		int n = nums.size();
		vector<int> f(n), g(n);
		if (nums[0] > 0) f[0] = 1;
		else if (nums[0] < 0) g[0] = 1;

		int res = f[0];
		for (int i = 1; i < n; i++)
		{
			if (nums[i] > 0)
			{
				f[i] = f[i - 1] + 1;
				if (g[i - 1]) g[i] = g[i - 1] + 1;
			}
			else if (nums[i] < 0) {
				if (g[i - 1]) f[i] = g[i - 1] + 1;
				g[i] = f[i - 1] + 1;
			}
			res = max(res, f[i]);
		}

		return res;
	}
};
