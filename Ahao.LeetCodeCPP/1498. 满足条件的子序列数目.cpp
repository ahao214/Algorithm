#include<vector>
#include <algorithm>

using namespace std;



/*
1498. 满足条件的子序列数目
给你一个整数数组 nums 和一个整数 target 。

请你统计并返回 nums 中能满足其最小元素与最大元素的 和 小于或等于 target 的 非空 子序列的数目。

由于答案可能很大，请将结果对 10^9 + 7 取余后返回。
*/
class Solution {
public:
	int numSubseq(vector<int>& nums, int target) {
		int n = nums.size(), mod = 1e9 + 7;
		vector<int> p(n);
		p[0] = 1;
		for (int i = 1; i < n; i++)
			p[i] = p[i - 1] * 2 % mod;

		sort(nums.begin(), nums.end());
		int res = 0;
		for (int i = 0, j = n - 1; i < n; i++)
		{
			while (j >= i && nums[i] + nums[j] > target) j--;
			if (j >= i && nums[i] + nums[j] <= target)
			{
				res = (res + p[j - i]) % mod;
			}
		}

		return res;
	}
};