#include<vector>

using namespace std;


/*
1463. 摘樱桃 II
给你一个 rows x cols 的矩阵 grid 来表示一块樱桃地。 grid 中每个格子的数字表示你能获得的樱桃数目。

你有两个机器人帮你收集樱桃，机器人 1 从左上角格子 (0,0) 出发，机器人 2 从右上角格子 (0, cols-1) 出发。

请你按照如下规则，返回两个机器人能收集的最多樱桃数目：

从格子 (i,j) 出发，机器人可以移动到格子 (i+1, j-1)，(i+1, j) 或者 (i+1, j+1) 。
当一个机器人经过某个格子时，它会把该格子内所有的樱桃都摘走，然后这个位置会变成空格子，即没有樱桃的格子。
当两个机器人同时到达同一个格子时，它们中只有一个可以摘到樱桃。
两个机器人在任意时刻都不能移动到 grid 外面。
两个机器人最后都要到达 grid 最底下一行。
*/
class Solution {
public:
	int cherryPickup(vector<vector<int>>& grid) {
		int n = grid.size(), m = grid[0].size();
		vector<vector<vector<int>>> f(n, vector<vector<int>>(m, vector<int>(m, -1)));

		f[0][0][m - 1] = grid[0][0] + grid[0][m - 1];
		int res = 0;
		for (int k = 1; k < n; k++)
		{
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < m; j++)
				{
					for (int a = i - 1; a <= i + 1; a++)
					{
						for (int b = j - 1; b <= j + 1; b++)
						{
							if (a < 0 || a >= m || b < 0 || b >= m)continue;
							int t = f[k - 1][a][b];
							if (t == -1) continue;
							if (i == j)
								t += grid[k][i];
							else
								t += grid[k][i] + grid[k][j];
							f[k][i][j] = max(t, f[k][i][j]);
							res = max(res, f[k][i][j]);
						}
					}
				}
			}
		}
		return res;
	}
};