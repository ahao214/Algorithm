using namespace std;
#include<vector>
#include <algorithm>


class Solution {
	/*
	40. 组合总和 II
	给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

	candidates 中的每个数字在每个组合中只能使用 一次 。

	注意：解集不能包含重复的组合。
	*/
	vector<vector<int>> ans;
	vector<int> combine;
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		dfs(candidates, target, 0);
		return ans;
	}

	void dfs(vector<int>& candidates, int target, int idx) {
		if (target == 0) {
			ans.push_back(combine);
			return;
		}
		if (idx == candidates.size()) return;
		int cnt = 1;
		while (idx + 1 < candidates.size() && candidates[idx] == candidates[idx + 1]) {
			idx++, cnt++;
		}
		for (int i = 0; i <= cnt && target >= i * candidates[idx]; i++) {
			dfs(candidates, target - i * candidates[idx], idx + 1);
			combine.push_back(candidates[idx]);
		}
		for (int i = 0; i <= cnt && target >= i * candidates[idx]; i++) {
			combine.pop_back();
		}
	}
};
