using namespace std;
#include<vector>


/*
39. 组合总和
给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。

candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。

对于给定的输入，保证和为 target 的不同组合数少于 150 个。
*/
class Solution {
	vector<vector<int>> ans;
	vector<int> combine;
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		dfs(candidates, target, 0);
		return ans;
	}

	void dfs(vector<int>& candidates, int target, int idx) {
		if (target == 0) {
			ans.push_back(combine);
			return;
		}
		if (idx == candidates.size()) return;
		dfs(candidates, target, idx + 1);
		if (target >= candidates[idx]) {
			combine.push_back(candidates[idx]);
			dfs(candidates, target - candidates[idx], idx);
			combine.pop_back();
		}
	}
};