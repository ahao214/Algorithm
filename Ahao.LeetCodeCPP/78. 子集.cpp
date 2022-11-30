#include<vector>

using namespace std;

class Solution {
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




/*
78. 子集
给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
*/
class Solution {

	void backtracking(vector<vector<int>>& res, vector<int>& path, vector<int>& nums, int start)
	{
		res.push_back(path);
		for (int i = start; i < nums.size(); i++)
		{
			path.push_back(nums[i]);
			backtracking(res, path, nums, i + 1);
			path.pop_back();
		}
	}
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> path;
		backtracking(res, path, nums, 0);
		return res;
	}
};



/*
78. 子集
给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
*/
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res;
		for (int i = 0; i < 1 << nums.size(); i++)
		{
			vector<int> now;
			for (int j = 0; j < nums.size(); j++)
			{
				//如果二进制的位置上的数是1
				if (i >> j & 1)
					now.push_back(nums[j]);
			}
			res.push_back(now);
		}
		return res;
	}
};