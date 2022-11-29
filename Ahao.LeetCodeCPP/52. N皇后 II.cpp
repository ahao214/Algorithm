using namespace std;
#include<vector>
#include<string>

/*
52. N皇后 II
n 皇后问题 研究的是如何将 n 个皇后放置在 n × n 的棋盘上，并且使皇后彼此之间不能相互攻击。

给你一个整数 n ，返回 n 皇后问题 不同的解决方案的数量。
*/
class Solution {
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



/*
52. N皇后 II
n 皇后问题 研究的是如何将 n 个皇后放置在 n × n 的棋盘上，并且使皇后彼此之间不能相互攻击。

给你一个整数 n ，返回 n 皇后问题 不同的解决方案的数量。
*/
class Solution {
public:
	int ans;
	vector<bool> row, col, diag, anti_diag;

	int totalNQueens(int n) {
		row = col = vector<bool>(n, false);
		diag = anti_diag = vector<bool>(2 * n, false);
		ans = 0;
		dfs(0, 0, 0, n);
		return ans;
	}

	void dfs(int x, int y, int s, int n)
	{
		if (y == n) x++, y = 0;
		if (x == n)
		{
			if (s == n) ++ans;
			return;
		}
		dfs(x, y + 1, s, n);
		if (!row[x] && !col[y] && !diag[x + y] && !anti_diag[n - 1 - x + y])
		{
			row[x] = col[y] = diag[x + y] = anti_diag[n - 1 - x + y] = true;
			dfs(x, y + 1, s + 1, n);
			row[x] = col[y] = diag[x + y] = anti_diag[n - 1 - x + y] = false;
		}
	}

	vector<bool> col, d, ud;
	int ans = 0, m;
	int totalNQueens(int n) {
		m = n;
		col = vector<bool>(m);
		d = ud = vector<bool>(m * 2);
		dfs(0);
		return ans;
	}

	void dfs(int u)
	{
		if (u == m)
		{
			ans++;
			return;
		}

		for (int i = 0; i < m; i++)
		{
			if (!col[i] && !d[u + i] && !ud[u - i + m])
			{
				col[i] = d[u + i] = ud[u - i + m] = true;
				dfs(u + 1);
				col[i] = d[u + i] = ud[u - i + m] = false;
			}
		}
	}
};
