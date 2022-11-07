#include<vector>

using namespace std;


/*
1712. 将数组分成三个子数组的方案数
我们称一个分割整数数组的方案是 好的 ，当它满足：

数组被分成三个 非空 连续子数组，从左至右分别命名为 left ， mid ， right 。
left 中元素和小于等于 mid 中元素和，mid 中元素和小于等于 right 中元素和。
给你一个 非负 整数数组 nums ，请你返回 好的 分割 nums 方案数目。由于答案可能会很大，请你将结果对 109 + 7 取余后返回。
*/
class Solution {
public:
	int waysToSplit(vector<int>& nums) {
		int n = nums.size(), mod = 1e9 + 7;
		vector<int> s(n + 1);
		for (int i = 1; i <= n; i++) s[i] = s[i - 1] + nums[i - 1];
		int res = 0;
		for (int i = 3, j = 2, k = 2; i <= n; i++)
		{
			while (s[n] - s[i - 1] < s[i - 1] - s[j - 1]) j++;
			while (k + 1 < i && s[i - 1] - s[k] >= s[k]) k++;
			if (j <= k && s[n] - s[i - 1] >= s[i - 1] - s[j - 1] && s[i - 1] - s[k - 1] >= s[k - 1])
				res = (res + k - j + 1) % mod;
		}
		return res;
	}
};
