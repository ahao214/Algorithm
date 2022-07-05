#include<vector>

using namespace std;



class Solution {
	/*
	77. 组合
	给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
	你可以按 任何顺序 返回答案。
	*/
public:
	vector<vector<int>> ans;
	vector<int> cur;
	vector<vector<int>> combine(int n, int k) {
		dfs(1, n, k);
		return ans;
	}

	void dfs(int start, int n, int k)
	{
		if (k == 0)
		{
			ans.push_back(cur);
			return;
		}
		for (int i = start; i <= n; i++)
		{
			cur.push_back(i);
			dfs(i + 1, n, k - 1);
			cur.pop_back();
		}
	}
};
