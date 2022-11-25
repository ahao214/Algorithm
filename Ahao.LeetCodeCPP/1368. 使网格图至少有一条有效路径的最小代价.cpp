#include<vector>
#include <deque>

using namespace std;



/*
1368. ʹ����ͼ������һ����Ч·������С����
����һ�� m x n ������ͼ grid ��
grid ��ÿ�����Ӷ���һ�����֣�
��Ӧ�ŴӸø��ӳ�����һ���ߵķ���
grid[i][j] �е����ֿ���Ϊ���¼��������
����1��ʾ��һ�������ߣ�Ҳ�������� grid[i][j] �ߵ� grid[i][j + 1]
����2��ʾ��һ�������ߣ�Ҳ�������� grid[i][j] �ߵ� grid[i][j - 1]
����3��ʾ��һ�������ߣ�Ҳ�������� grid[i][j] �ߵ� grid[i + 1][j]
����4��ʾ��һ�������ߣ�Ҳ�������� grid[i][j] �ߵ� grid[i - 1][j]
ע������ͼ�п��ܻ��� ��Ч���� ����Ϊ���ǿ���ָ�� grid ���������

һ��ʼ�����������Ͻǵĸ��� (0,0) ������
���Ƕ���һ�� ��Ч·�� Ϊ�Ӹ��� (0,0) ������
ÿһ����˳�����ֶ�Ӧ�����ߣ������������½ǵĸ��� (m - 1, n - 1)
������·������Ч·�� ����Ҫ�����·�� ��

����Ի��� cost = 1 �Ĵ����޸�һ�������е����֣�
��ÿ�������е����� ֻ���޸�һ�� ��

���㷵��������ͼ������һ����Ч·������С���ۡ�
*/
class Solution {
public:
	int minCost(vector<vector<int>>& grid) {
		typedef pair<int, int> PII;
		const int INF = 0x3f3f3f3f;
		int n = grid.size(), m = grid[0].size();

		vector<vector<int>> dist(n, vector<int>(m, INF));
		vector<vector<bool>> st(n, vector<bool>(m));

		int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };

		deque<PII> q;
		q.push_back({ 0,0 });
		dist[0][0] = 0;

		while (q.size())
		{
			auto t = q.front();
			q.pop_front();

			if (st[t.first][t.second]) continue;
			st[t.first][t.second] = true;

			for (int i = 0; i < 4; i++)
			{
				int x = t.first + dx[i], y = t.second + dy[i];
				if (x < 0 || x >= n || y < 0 || y >= m)
					continue;

				int w = grid[t.first][t.second] - 1 != i;
				if (dist[x][y] > dist[t.first][t.second] + w)
				{
					dist[x][y] = dist[t.first][t.second] + w;
					if (w == 0) q.push_front({ x,y });
					else q.push_back({ x,y });
				}
			}
		}
		return dist[n - 1][m - 1];
	}
};
