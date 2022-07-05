#include<vector>

using namespace std;



class Solution {
	/*
	77. ���
	������������ n �� k�����ط�Χ [1, n] �����п��ܵ� k ��������ϡ�
	����԰� �κ�˳�� ���ش𰸡�
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
