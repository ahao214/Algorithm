#include<vector>

using namespace std;


/*
1749. 任意子数组和的绝对值的最大值
给你一个整数数组 nums 。一个子数组 [numsl, numsl+1, ..., numsr-1, numsr] 的 和的绝对值 为 abs(numsl + numsl+1 + ... + numsr-1 + numsr) 。

请你找出 nums 中 和的绝对值 最大的任意子数组（可能为空），并返回该 最大值 。

abs(x) 定义如下：

如果 x 是负整数，那么 abs(x) = -x 。
如果 x 是非负整数，那么 abs(x) = x 。
*/
class Solution {
public:
	/*前缀和*/
	int maxAbsoluteSum(vector<int>& nums) {
		int n = nums.size();
		vector<int> s(n + 1);
		for (int i = 1; i < n; i++)
			s[i] = s[i - 1] + nums[i - 1];
		int res = 0;
		int minv = 0, maxv = 0;
		for (int i = 1; i <= n; i++)
		{
			res = max(res, abs(s[i] - minv));
			res = max(res, abs(s[i] - maxv));
			minv = min(minv, s[i]);
			maxv = max(maxv, s[i]);
		}
		return res;
	}
};
