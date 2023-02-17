#include<vector>

using namespace std;

/*
840. 矩阵中的幻方

3 x 3 的幻方是一个填充有 从 1 到 9  的不同数字的 3 x 3 矩阵，其中每行，每列以及两条对角线上的各数之和都相等。

给定一个由整数组成的row x col 的 grid，其中有多少个 3 × 3 的 “幻方” 子矩阵？（每个子矩阵都是连续的）。


示例 1：

输入: grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]
输出: 1
解释:
下面的子矩阵是一个 3 x 3 的幻方：

而这一个不是：

总的来说，在本示例所给定的矩阵中只有一个 3 x 3 的幻方子矩阵。
示例 2:

输出: grid = [[8]]
输入: 0


提示:

row == grid.length
col == grid[i].length
1 <= row, col <= 10
0 <= grid[i][j] <= 15
*/

class Solution {
public:
	vector<vector<int>> g;
	bool check(int x, int y)
	{
		bool st[10] = { 0 };
		for (int i = x; i < x + 3; i++)
		{
			for (int j = y; j < y + 3; j++)
			{
				int t = g[i][j];
				if (t < 1 || t > 9) return false;
				if (st[t]) return false;
				st[t] = true;
			}
		}

		for (int i = 0; i < 3; i++)
		{
			if (g[x + i][y] + g[x + i][y + 1] + g[x + i][y + 2] != 15) return false;
			if (g[x][y + i] + g[x + 1][y + i] + g[x + 2][y + i] != 15) return false;
		}
		//对角线
		if (g[x][y] + g[x + 1][y + 1] + g[x + 2][y + 2] != 15) return false;
		if (g[x + 2][y] + g[x + 1][y + 1] + g[x][y + 2] != 15) return false;
		return true;
	}

	int numMagicSquaresInside(vector<vector<int>>& grid) {
		g = grid;
		int res = 0;
		int m = grid.size(), n = grid[0].size();
		for (int i = 0; i + 3 <= m; i++)
			for (int j = 0; j + 3 <= n; j++)
				if (check(i, j))
					res++;
		return res;
	}
};

