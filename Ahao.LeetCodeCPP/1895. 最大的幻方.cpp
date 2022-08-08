#include<vector>

using namespace std;


/*
1895. 最大的幻方
一个 k x k 的 幻方 指的是一个 k x k 填满整数的方格阵，且每一行、每一列以及两条对角线的和 全部相等 。幻方中的整数 不需要互不相同 。显然，每个 1 x 1 的方格都是一个幻方。

给你一个 m x n 的整数矩阵 grid ，请你返回矩阵中 最大幻方 的 尺寸 （即边长 k）。
*/
typedef long long LL;
class Solution {
public:
	bool check(vector<vector<int>>& g, int a, int b, int c, int d)
	{
		LL sum = 0;
		for (int i = a; i <= c; i++)
		{
			LL s = 0;
			for (int j = b; j <= d; j++)
				s += g[i][j];
			if (sum && sum != s)return false;
			sum = s;
		}
		for (int i = b; i <= d; i++)
		{
			LL s = 0;
			for (int j = a; j <= c; j++)
			{
				s += g[j][i];
			}
			if (sum != s)return false;
		}

		LL s = 0;
		for (int i = a, j = b; i <= c; i++, j++)
			s += g[i][j];
		if (s != sum) return false;

		s = 0;
		for (int i = a, j = d; i <= c; i++, j--)
			s += g[i][j];
		return s == sum;
	}

	int largestMagicSquare(vector<vector<int>>& grid) {
		int n = grid.size(), m = grid[0].size();
		for (int k = min(n, m); k; k--)
			for (int i = 0; i + k - 1 < n; i++)
				for (int j = 0; j + k - 1 < m; j++)
					if (check(grid, i, j, i + k - 1, j + k - 1))
						return k;
		return 1;
	}

};

