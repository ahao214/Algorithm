#include<vector>
#include <string>

using namespace std;


/*
1519. �����б�ǩ��ͬ�Ľڵ���
����һ����������һ����ͨ���޻�����ͼ����������ɱ�Ŵ� 0  �� n - 1 �� n ���ڵ���ɣ���ǡ���� n - 1 �� edges �����ĸ��ڵ�Ϊ�ڵ� 0 �����ϵ�ÿһ���ڵ㶼��һ����ǩ��Ҳ�����ַ��� labels �е�һ��Сд�ַ������Ϊ i �� �ڵ�ı�ǩ���� labels[i] ��

������ edges �� edges[i] = [ai, bi] ����ʽ�������ø�ʽ��ʾ�ڵ� ai �� bi ֮�����һ���ߡ�

����һ����СΪ n �����飬���� ans[i] ��ʾ�� i ���ڵ����������ڵ� i ��ǩ��ͬ�Ľڵ�����

�� T �е��������� T �е�ĳ���ڵ㼰�����к���ڵ���ɵ�����
*/
class Solution {
public:
	vector<vector<int>> f;
	vector<vector<int>> g;
	string w;

	vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
		g.resize(n);
		f = vector<vector<int>>(n, vector<int>(26));
		w = labels;

		for (auto& e : edges)
		{
			int a = e[0], b = e[1];
			g[a].push_back(b), g[b].push_back(a);
		}

		dfs(0, -1);
		vector<int> res(n);
		for (int i = 0; i < n; i++) res[i] = f[i][w[i] - 'a'];
		return res;
	}

	void dfs(int u, int father)
	{
		f[u][w[u] - 'a'] = 1;
		for (auto son : g[u])
		{
			if (son == father) continue;
			dfs(son, u);
			for (int j = 0; j < 26; j++)
			{
				f[u][j] += f[son][j];
			}
		}
	}
};