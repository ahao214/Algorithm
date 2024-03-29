#include<vector>

using namespace std;


/*
300. 最长递增子序列
给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。

子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而
不改变其余元素的顺序。
例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。
*/
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int n = nums.size();
		vector<int> f(n);
		for (int i = 0; i < n; i++)
		{
			f[i] = 1;
			for (int j = 0; j < i; j++)
			{
				if (nums[j] < nums[i])
					f[i] = max(f[i], f[j] + 1);
			}
		}
		int res = 0;
		for (int i = 0; i < n; i++)
			res = max(res, f[i]);
		return res;
	}
};