using namespace std;
#include<vector>
#include <algorithm>


class Solution {
	/*
	40. ����ܺ� II
	����һ����ѡ�˱�ŵļ��� candidates ��һ��Ŀ���� target ���ҳ� candidates �����п���ʹ���ֺ�Ϊ target ����ϡ�

	candidates �е�ÿ��������ÿ�������ֻ��ʹ�� һ�� ��

	ע�⣺�⼯���ܰ����ظ�����ϡ�
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
