#include<vector>

using namespace std;


/*
77. ���

������������ n �� k�����ط�Χ [1, n] �����п��ܵ� k ��������ϡ�

����԰� �κ�˳�� ���ش𰸡�
*/
class Solution {
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




class Solution {
	vector<vector<int>> res;
public:
	vector<vector<int>> combine(int n, int k) {
		vector<int> comb;
		DFS(n, k, 1, comb);
		return res;
	}

	void DFS(int n, int k, int cur, vector<int>& comb) {
		if (comb.size() == k) {
			res.push_back(comb);
			return;
		}
		for (int i = cur; i <= n; i++) {
			comb.push_back(i);
			DFS(n, k, i + 1, comb);
			comb.pop_back();
		}
	}
};