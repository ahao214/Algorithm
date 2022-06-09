using namespace std;

#include<vector>


class Solution {
	/*
	63. 不同路径 II
	一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

	机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish”）。

	现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？

	网格中的障碍物和空位置分别用 1 和 0 来表示。
	*/
public:
	/*
	Times:O(m*n)
	Space:O(m*n)
	*/
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size(), n = obstacleGrid[0].size();
		vector<vector<int>> f(m, vector<int>(n));
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (obstacleGrid[i][j] == 1) continue;
				if (!i && !j)
					f[i][j] = 1;
				else
				{
					if (i) f[i][j] += f[i - 1][j];
					if (j) f[i][j] += f[i][j - 1];
				}
			}
		}
		return f[m - 1][n - 1];
	}

}