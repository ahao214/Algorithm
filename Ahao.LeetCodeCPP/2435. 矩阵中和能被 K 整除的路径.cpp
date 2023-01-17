#include<vector>

using namespace std;



/*
2435. 矩阵中和能被 K 整除的路径
给你一个下标从 0 开始的 m x n 整数矩阵 grid 和一个整数 k 。你从起点 (0, 0) 出发，每一步只能往 下 或者往 右 ，你想要到达终点 (m - 1, n - 1) 。

请你返回路径和能被 k 整除的路径数目，由于答案可能很大，返回答案对 109 + 7 取余 的结果。
*/
using LL = long long;
LL M = 1e9 + 7;
class Solution {
public:
	int numberOfPaths(vector<vector<int>>& grid, int k) {
		int m = grid.size();
		int n = grid[0].size();
		vector<vector<vector<LL>>> dp(m, vector<vector<LL>>(n, vector<LL>(k, 0)));
		LL sum = 0;
		for (int i = 0; i < m; i++) {
			sum = (sum + grid[i][0]) % M;
			dp[i][0][sum % k] = 1;
		}

		sum = 0;
		for (int j = 0; j < n; j++) {
			sum = (sum + grid[0][j]) % M;
			dp[0][j][sum % k] = 1;
		}

		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				for (int r = 0; r < k; r++) {
					int t = ((r - grid[i][j]) % k + k) % k;
					dp[i][j][r] = (dp[i - 1][j][t] + dp[i][j - 1][t]) % M;
				}
			}
		}
		return dp[m - 1][n - 1][0];
	}
};

