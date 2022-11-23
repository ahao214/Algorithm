#include<vector>

using namespace std;



/*
1466. ���¹滮·��
n �����У��� 0 �� n-1 ��ţ���乲�� n-1 ��·�ߡ���ˣ�Ҫ����������ͬ����֮������ֻ��Ψһһ��·�߿ɹ�ѡ��·�����γ�һ��������ȥ�꣬��ͨ���䲿�������¹滮·�ߣ��Ըı佻ͨӵ�µ�״����

·���� connections ��ʾ������ connections[i] = [a, b] ��ʾ�ӳ��� a �� b ��һ������·�ߡ�

���꣬���� 0 ����ٰ�һ�����ͱ������ܶ��οͶ���ǰ������ 0 ��

����������¹滮·�߷���ʹÿ�����ж����Է��ʳ��� 0 ��������Ҫ����������С·������

��Ŀ���� ��֤ ÿ�����������¹滮·�߷�����ܵ������ 0 ��
*/
class Solution {
public:
	vector<vector<pair<int, int>>> g;
	int minReorder(int n, vector<vector<int>>& connections) {
		g = vector<vector<pair<int, int>>>(n);
		for (auto e : connections)
		{
			int a = e[0], b = e[1];
			g[a].push_back({ b,1 });
			g[b].push_back({ a,0 });
		}
		return dfs(0, -1);
	}

	int dfs(int u, int father)
	{
		int res = 0;
		for (auto e : g[u])
		{
			int ver = e.first, dir = e.second;
			if (ver == father) continue;
			res += dfs(ver, u) + dir;
		}
		return res;
	}
};
