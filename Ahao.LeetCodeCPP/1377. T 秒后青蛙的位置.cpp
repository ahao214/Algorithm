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