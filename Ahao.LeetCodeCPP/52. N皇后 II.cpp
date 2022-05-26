using namespace std;
#include<vector>
#include<string>


class Solution {
	/*
	52. N皇后 II
	n 皇后问题 研究的是如何将 n 个皇后放置在 n × n 的棋盘上，并且使皇后彼此之间不能相互攻击。

	给你一个整数 n ，返回 n 皇后问题 不同的解决方案的数量。
	*/
	vector<bool> col, dg, udg;
	int ans = 0;
public:
	int totalNQueens(int n) {
		col = vector<bool>(n);
		dg = udg = vector<bool>(2 * n);
		dfs(0, n);
		return ans;
	}

	void dfs(int x, int n)
	{
		if (x == n)
		{
			ans++;
			return;
		}
		for (int y = 0; y < n; y++)
		{
			if (col[y] || udg[y - x + n] || dg[y + x]) continue;
			col[y] = udg[y - x + n] = dg[y + x] = true;
			dfs(x + 1, n);
			col[y] = udg[y - x + n] = dg[y + x] = false;
		}
	}
};
