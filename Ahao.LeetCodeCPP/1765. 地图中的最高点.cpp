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
class Solution {
public:
	vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
		int m = isWater.size(), n = isWater[0].size();
		queue<pair<int, int>> q;
		vector<vector<int>> vis(m, vector<int>(n)), dis(m, vector<int>(n));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				//ˮ����ӣ��߶�Ϊ0����ΪBFS�ĳ�ʼ�ڵ�
				if (isWater[i][j] == 1) {
					q.push({ i,j });
					dis[i][j] = 0;
					vis[i][j] = 1;
				}
			}
		}
		const vector<vector<int>> dirs = { {-1,0},{1,0},{0,1},{0,-1} };
		while (!q.empty()) {
			auto [cx, cy] = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				int x = cx + dirs[i][0], y = cy + dirs[i][1];
				if (x < 0 || x >= m || y < 0 || y >= n)continue;
				if (!vis[x][y] && isWater[x][y] == 0) {
					dis[x][y] = dis[cx][cy] + 1;
					q.push({ x,y });
					vis[x][y] = 1;
				}
			}
		}
		return dis;
	}
};