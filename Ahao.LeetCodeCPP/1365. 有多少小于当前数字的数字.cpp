#include<vector>

using namespace std;


/*
1365. 有多少小于当前数字的数字
给你一个数组 nums，对于其中每个元素 nums[i]，请你统计数组中比它小的所有数字的数目。

换而言之，对于每个 nums[i] 你必须计算出有效的 j 的数量，其中 j 满足 j != i 且 nums[j] < nums[i] 。

以数组形式返回答案。
*/
class Solution {
public:
	vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
		vector<int> res(nums.size());
		for (int i = 0; i < nums.size(); i++)
		{
			for (auto y : nums)
				if (y < nums[i])
					res[i]++;
		}
		return res;
	}
};
