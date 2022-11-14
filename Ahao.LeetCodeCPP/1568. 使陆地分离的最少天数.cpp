#include<vector>

using namespace std;



/*
1568. ʹ½�ط������������
����һ�������� 0 �� 1 ��ɵĶ�ά���� grid ������ 0 ��ʾˮ���� 1 ��ʾ½�ء�������ˮƽ�������ֱ���������ڵ� 1 ��½�أ������γɡ�

��� ǡ��ֻ��һ������ ������Ϊ½���� ��ͨ�� ������½�ؾ��� ����� ��

һ���ڣ����Խ��κε���½�ص�Ԫ��1������Ϊˮ��Ԫ��0����

����ʹ½�ط��������������
*/
class Solution {
public:
	int n, m;
	vector<vector<bool>> st;
	vector<vector<int>> g;
	int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };

	void dfs(int x, int y)
	{
		st[x][y] = true;
		for (int i = 0; i < 4; i++)
		{
			int a = x + dx[i], b = y + dy[i];
			if (a >= 0 && a < n && b >= 0 && b < m && !st[a][b] && g[a][b] == 1)
				dfs(a, b);
		}
	}

	bool check() {
		int cnt = 0;
		st = vector<vector<bool>>(n, vector<bool>(m));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (!st[i][j] && g[i][j] == 1)
				{
					cnt++;
					dfs(i, j);
				}
			}
		}
		return cnt > 1 || !cnt;
	}

	int minDays(vector<vector<int>>& grid) {
		n = grid.size(), m = grid[0].size();
		g = grid;

		if (check()) return 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (g[i][j])
				{
					g[i][j] = 0;
					if (check()) return 1;
					g[i][j] = 1;
				}
			}
		}
		return 2;
	}
};