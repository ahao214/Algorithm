#include<vector>

using namespace std;


/*
1473. 粉刷房子 III
在一个小城市里，有 m 个房子排成一排，你需要给每个房子涂上 n 种颜色之一（颜色编号为 1 到 n ）。有的房子去年夏天已经涂过颜色了，所以这些房子不可以被重新涂色。

我们将连续相同颜色尽可能多的房子称为一个街区。（比方说 houses = [1,2,2,3,3,2,1,1] ，它包含 5 个街区  [{1}, {2,2}, {3,3}, {2}, {1,1}] 。）

给你一个数组 houses ，一个 m * n 的矩阵 cost 和一个整数 target ，其中：

houses[i]：是第 i 个房子的颜色，0 表示这个房子还没有被涂色。
cost[i][j]：是将第 i 个房子涂成颜色 j+1 的花费。
请你返回房子涂色方案的最小总花费，使得每个房子都被涂色后，恰好组成 target 个街区。如果没有可用的涂色方案，请返回 -1 。
*/
class Solution {
public:
	int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
		const int INF = 1e8;
		vector<vector<vector<int>>> f(m, vector<vector<int>>(m + 1, vector<int>(n + 1, INF)));

		if (houses[0]) f[0][1][houses[0]] = 0;
		else
		{
			for (int i = 1; i <= n; i++)
			{
				f[0][1][i] = cost[0][i - 1];
			}
		}

		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j <= target; j++)
			{
				if (houses[i])
				{
					int k = houses[i];
					for (int u = 1; u <= n; u++)
					{
						if (u == k)
							f[i][j][k] = min(f[i][j][k], f[i - 1][j][u]);
						else
							f[i][j][k] = min(f[i][j][k], f[i - 1][j - 1][u]);
					}
				}
				else {
					for (int k = 1; k <= n; k++)
					{
						for (int u = 1; u <= n; u++)
						{
							if (u == k)
								f[i][j][k] = min(f[i][j][k], f[i - 1][j][u] + cost[i][k - 1]);
							else
								f[i][j][k] = min(f[i][j][k], f[i - 1][j - 1][u] + cost[i][k - 1]);
						}
					}
				}
			}
		}
		int res = INF;
		for (int i = 1; i <= n; i++)
		{
			res = min(res, f[m - 1][target][i]);
		}
		if (res == INF)
			res = -1;
		return res;
	}
};