#include<vector>

using namespace std;


/*
152. 乘积最大子数组

给你一个整数数组 nums ，请你找出数组中乘积最大的非空连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。

测试用例的答案是一个 32-位 整数。

子数组 是数组的连续子序列。
*/

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int res = nums[0];
		int f = nums[0], g = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			int a = nums[i], fa = f * a, ga = g * a;
			f = max(a, max(fa, ga));
			g = min(a, min(fa, ga));
			res = max(res, f);
		}
		return res;
	}
};