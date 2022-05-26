using namespace std;
#include<vector>
#include<string>

class Solution {
	/*
	51. N 皇后
	n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

	给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。

	每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
	*/
	//col:列 dg:对角线 udg:斜对角线
	vector<bool> col, dg, udg;
	vector<string> path;
	vector<vector<string>> ans;
public:
	vector<vector<string>> solveNQueens(int n) {
		col = vector<bool>(n);
		dg = udg = vector<bool>(2 * n);
		path = vector<string>(n, string(n, '.'));
		dfs(0, n);
		return ans;
	}

	void dfs(int x, int n)
	{
		if (x == n)
		{
			ans.push_back(path);
			return;
		}
		for (int y = 0; y < n; y++)
		{
			if (col[y] || udg[y - x + n] || dg[y + x]) continue;
			col[y] = udg[y - x + n] = dg[y + x] = true;
			path[x][y] = 'Q';
			dfs(x + 1, n);
			path[x][y] = '.';
			col[y] = udg[y - x + n] = dg[y + x] = false;
		}
	}

};
