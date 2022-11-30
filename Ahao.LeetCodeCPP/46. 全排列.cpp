using namespace std;
#include<vector>

/*
46. 全排列
给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
*/
class Solution {
	vector<vector<int>> ans;
	vector<int> combine;
	vector<bool> used;
public:
	vector<vector<int>> permute(vector<int>& nums) {
		used = vector<bool>(nums.size());
		dfs(nums, 0);
		return ans;
	}

	void dfs(vector<int>& nums, int idx)
	{
		if (idx == nums.size())
		{
			ans.push_back(combine);
			return;
		}
		for (int i = 0; i < nums.size(); i++)
		{
			if (!used[i])
			{
				combine.push_back(nums[i]);
				used[i] = true;
				dfs(nums, idx + 1);
				used[i] = false;
				combine.pop_back();
			}
		}
	}
};



/*
46. 全排列
给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
*/
class Solution {
public:
	int n;
	vector<bool> st;
	vector<vector<int>> ans;
	vector<int> path;

	vector<vector<int>> permute(vector<int>& nums) {
		n = nums.size();
		st = vector<bool>(n);
		dfs(nums, 0);
		return ans;
	}

	void dfs(vector<int>& nums, int u)
	{
		if (u == n)
		{
			ans.push_back(path);
			return;
		}

		for (int i = 0; i < n; i++)
		{
			if (!st[i])
			{
				st[i] = true;
				path.push_back(nums[i]);
				dfs(nums, u + 1);
				path.pop_back();
				st[i] = false;
			}
		}
	}
};
