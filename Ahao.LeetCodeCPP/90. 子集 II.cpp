#include<vector>
#include <algorithm>

using namespace std;


/*
90. 子集 II
给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。
*/
class Solution {
public:
	vector<vector<int>> ans;
	vector<int> path;

	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		dfs(nums, 0);
		return ans;
	}

	void dfs(vector<int>& nums, int u)
	{
		if (u == nums.size())
		{
			ans.push_back(path);
			return;
		}

		//计算当前数字的个数
		int k = 0;
		while (u + k < nums.size() && nums[u + k] == nums[u]) k++;
		for (int i = 0; i <= k; i++)
		{
			dfs(nums, u + k);
			path.push_back(nums[u]);
		}

		//恢复现场
		for (int i = 0; i <= k; i++)
			path.pop_back();
	}
};