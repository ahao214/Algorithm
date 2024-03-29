#include<vector>

using namespace std;


/*
216. 组合总和 III
找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。

说明：

所有数字都是正整数。
解集不能包含重复的组合。
*/
class Solution {
public:
	vector<vector<int>> ans;
	vector<int> path;
	vector<vector<int>> combinationSum3(int k, int n) {
		dfs(k, 1, n);
		return ans;
	}

	void dfs(int k, int start, int n)
	{
		if (!k)
		{
			if (!n) ans.push_back(path);
			return;
		}
		for (int i = start; i <= 10 - k; i++)
		{
			path.push_back(i);
			dfs(k - 1, i + 1, n - i);
			path.pop_back();
		}
	}
};
