#include<vector>
#include<queue>

using namespace std;



/*
1765. ��ͼ�е���ߵ�
����һ����СΪ m x n ���������� isWater ����������һ���� ½�� �� ˮ�� ��Ԫ����ɵĵ�ͼ��

��� isWater[i][j] == 0 ������ (i, j) ��һ�� ½�� ���ӡ�
��� isWater[i][j] == 1 ������ (i, j) ��һ�� ˮ�� ���ӡ�
����Ҫ�������¹����ÿ����Ԫ���Ÿ߶ȣ�

ÿ�����ӵĸ߶ȶ������ǷǸ��ġ�
���һ�������� ˮ�� ����ô���ĸ߶ȱ���Ϊ 0 ��
�������ڵĸ��Ӹ߶Ȳ� ���� Ϊ 1 ���������������������ϡ��������������໥�����ţ��ͳ�����Ϊ���ڵĸ��ӡ���Ҳ����˵������һ�������ߣ�
�ҵ�һ�ְ��Ÿ߶ȵķ�����ʹ�þ����е���߸߶�ֵ ��� ��

���㷵��һ����СΪ m x n ���������� height ������ height[i][j] �Ǹ��� (i, j) �ĸ߶ȡ�����ж��ֽⷨ���뷵�� ����һ�� ��
*/
#define x first
#define y second
class Solution {
public:
	vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
		typedef pair<int, int> PII;
		const int INF = 1e8;

		int n = isWater.size(), m = isWater[0].size();
		vector<vector<int>> d(n, vector<int>(m, INF));
		queue<PII> q;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (isWater[i][j])
				{
					d[i][j] = 0;
					q.push({ i,j });
				}
			}
		}

		int dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 };
		while (q.size())
		{
			auto t = q.front();
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int x = t.x + dx[i], y = t.y + dy[i];
				if (x < 0 || x >= n || y < 0 || y >= m)
					continue;
				if (d[x][y] > d[t.x][t.y] + 1)
				{
					d[x][y] = d[t.x][t.y] + 1;
					q.push({ x,y });
				}
			}
		}
		return d;
	}
};
