#include<vector>

using namespace std;



/*
2435. �����к��ܱ� K ������·��
����һ���±�� 0 ��ʼ�� m x n �������� grid ��һ������ k �������� (0, 0) ������ÿһ��ֻ���� �� ������ �� ������Ҫ�����յ� (m - 1, n - 1) ��

���㷵��·�����ܱ� k ������·����Ŀ�����ڴ𰸿��ܴܺ󣬷��ش𰸶� 109 + 7 ȡ�� �Ľ����
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

