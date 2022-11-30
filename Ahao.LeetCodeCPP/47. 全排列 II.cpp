using namespace std;
#include<vector>
#include <algorithm>


/*
47. 全排列 II
给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
*/
class Solution {
	vector<vector<int>> ans;
	vector<int> combine;
	vector<bool> used;
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		used = vector<bool>(nums.size());
		sort(nums.begin(), nums.end());

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
				if (i && nums[i - 1] == nums[i] && !used[i - 1]) continue;
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
47. 全排列 II
给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
*/
class Solution {
public:
	int n;
	vector<vector<int>> ans;
	vector<int> path;
	vector<bool> st;
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		n = nums.size();
		st = vector<bool>(n);
		path = vector<int>(n);
		sort(nums.begin(), nums.end());
		dfs(nums, 0, 0);
		return ans;
	}

	void dfs(vector<int>& nums, int u, int start)
	{
		if (u == n)
		{
			ans.push_back(path);
			return;
		}
		for (int i = start; i < n; i++)
		{
			if (!st[i])
			{
				st[i] = true;
				path[i] = nums[u];
				dfs(nums, u + 1, u + 1 < n && nums[u + 1] == nums[u] ? i + 1 : 0);
				st[i] = false;
			}
		}
	}
};