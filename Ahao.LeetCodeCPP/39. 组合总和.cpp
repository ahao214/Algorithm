using namespace std;
#include<vector>
#include <algorithm>


/*
39. ����ܺ�
����һ�� ���ظ�Ԫ�� ���������� candidates ��һ��Ŀ������ target ���ҳ� candidates �п���ʹ���ֺ�ΪĿ���� target �� ���� ��ͬ��� �������б���ʽ���ء�����԰� ����˳�� ������Щ��ϡ�

candidates �е� ͬһ�� ���ֿ��� �������ظ���ѡȡ ���������һ�����ֵı�ѡ������ͬ������������ǲ�ͬ�ġ�

���ڸ��������룬��֤��Ϊ target �Ĳ�ͬ��������� 150 ����
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



/*
39. ����ܺ�
����һ�� ���ظ�Ԫ�� ���������� candidates ��һ��Ŀ������ target ���ҳ� candidates �п���ʹ���ֺ�ΪĿ���� target �� ���� ��ͬ��� �������б���ʽ���ء�����԰� ����˳�� ������Щ��ϡ�

candidates �е� ͬһ�� ���ֿ��� �������ظ���ѡȡ ���������һ�����ֵı�ѡ������ͬ������������ǲ�ͬ�ġ�

���ڸ��������룬��֤��Ϊ target �Ĳ�ͬ��������� 150 ����
*/
class Solution {
	void backtracking(vector<int>& candidates, vector<vector<int>>& res, vector<int>& path, int remain, int start)
	{
		if (remain == 0)
		{
			res.push_back(path);
			return;
		}
		if (remain < 0)
		{
			return;
		}
		for (int i = start; i < candidates.size(); i++)
		{
			path.push_back(candidates[i]);
			backtracking(candidates, res, path, remain - candidates[i], i);
			path.pop_back();
		}
	}
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> res;
		vector<int> path;
		sort(candidates.begin(), candidates.end());
		backtracking(candidates, res, path, target, 0);
		return res;
	}
};