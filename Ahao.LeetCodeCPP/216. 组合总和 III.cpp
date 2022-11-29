#include<vector>

using namespace std;


/*
216. ����ܺ� III
�ҳ��������֮��Ϊ n �� k ��������ϡ������ֻ������ 1 - 9 ��������������ÿ������в������ظ������֡�

˵����

�������ֶ�����������
�⼯���ܰ����ظ�����ϡ�
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
