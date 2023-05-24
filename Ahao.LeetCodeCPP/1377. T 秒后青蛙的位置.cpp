#include<vector>

using namespace std;


/*
1377. T ������ܵ�λ��

����һ���� n ��������ɵ��������������Ŵ� 1 �� n�����ܴ� ���� 1 ��ʼ�������������£�

��һ���ڣ����ܴ������ڵĵ�ǰ����������һ�� δ���� ���Ķ��㣨�������ֱ����������
�����޷������Ѿ����ʹ��Ķ��㡣
������ܿ������������ͬ���㣬��ô��������������һ�������ϵĻ��ʶ���ͬ��
������ܲ��������κ�δ���ʹ��Ķ����ϣ���ô��ÿ����Ծ����ͣ����ԭ�ء�
�������ı������� edges ���������� edges[i] = [fromi, toi] ��ζ�Ŵ���һ��ֱ����ͨ fromi �� toi ��������ıߡ�

���������� t ���λ��Ŀ�궥�� target �ϵĸ��ʡ�
*/
class Solution {
public:
	vector<vector<int>> e;
	double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
		e = vector<vector<int>>(n + 1);

		for (auto edge : edges)
		{
			int a = edge[0], b = edge[1];
			e[a].push_back(b);
			e[b].push_back(a);
		}
		return dfs(1, -1, t, target, 1);
	}

	double dfs(int u, int father, int t, int target, double p)
	{
		if (t == 0)
		{
			if (u == target) return p;
			return 0;
		}
		int k = e[u].size();
		if (u != 1) k--;

		if (!k)
		{
			if (u == target) return p;
			return 0;
		}

		double res = 0;
		for (auto s : e[u])
		{
			if (s != father)
				res = max(res, dfs(s, u, t - 1, target, p * 1.0 / k));
		}
		return res;
	}
};


class Solution {
public:
	double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
		vector<vector<int>> G(n + 1);
		for (int i = 0; i < edges.size(); ++i) {
			G[edges[i][0]].push_back(edges[i][1]);
			G[edges[i][1]].push_back(edges[i][0]);
		}
		vector<bool> visited(n + 1, false);
		return dfs(G, visited, 1, t, target);
	}

	double dfs(vector<vector<int>>& G, vector<bool>& visited, int i, int t, int target) {
		int nxt = i == 1 ? G[i].size() : G[i].size() - 1;
		if (t == 0 || nxt == 0) {
			return i == target ? 1.0 : 0.0;
		}
		visited[i] = true;
		double ans = 0.0;
		for (int j : G[i]) {
			if (!visited[j]) {
				ans += dfs(G, visited, j, t - 1, target);
			}
		}
		return ans / nxt;
	}
};
