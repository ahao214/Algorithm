#include<vector>

using namespace std;

class Solution {
	/*
	78. 子集
	给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。

	解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
	*/
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		int n = nums.size();
		vector<vector<int>> ans;
		for (int mask = 0; mask < (1 << n); mask++)
		{
			vector<int> subset;
			for (int i = 0; i < n; i++)
			{
				if (mask & (1 << i)) subset.push_back(nums[i]);
			}
			ans.push_back(subset);
		}
		return ans;
	}
};
