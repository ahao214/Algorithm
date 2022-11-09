#include<vector>
#include <unordered_map>

using namespace std;


/*
1695. 删除子数组的最大得分
给你一个正整数数组 nums ，请你从中删除一个含有 若干不同元素 的子数组。删除子数组的 得分 就是子数组各元素之 和 。

返回 只删除一个 子数组可获得的 最大得分 。

如果数组 b 是数组 a 的一个连续子序列，即如果它等于 a[l],a[l+1],...,a[r] ，那么它就是 a 的一个子数组。
*/
class Solution {
public:
	int maximumUniqueSubarray(vector<int>& nums) {
		unordered_map<int, int> hash;
		int res = 0;
		for (int i = 0, j = 0, sum = 0; i < nums.size(); i++)
		{
			int x = nums[i];
			hash[x]++;
			sum += x;
			while (hash[x] > 1)
			{
				sum -= nums[j];
				hash[nums[j++]]--;
			}
			res = max(res, sum);
		}

		return res;
	}
};