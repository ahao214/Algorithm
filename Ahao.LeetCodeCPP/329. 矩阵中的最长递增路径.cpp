#include<vector>

using namespace std;

/*
329. �����е������·��
����һ�� m x n �������� matrix ���ҳ����������·���ĳ��ȡ�

����ÿ����Ԫ����������ϣ��£������ĸ������ƶ��� �㲻���ڶԽ��� �������ƶ����ƶ��� �߽��⣨���������ƣ���
*/
class Solution {
public:
	vector<vector<int>> f;
	int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
	int n, m;
	int dp(int x, int y, vector<vector<int>>& matrix)
	{
		if (f[x][y] != -1) return f[x][y];
		f[x][y] = 1;
		for (int i = 0; i < 4; i++)
		{
			int a = x + dx[i], b = y + dy[i];
			if (a >= 0 && a < n && b >= 0 && b<m && matrix[a][b] > matrix[x][y])
			{
				f[x][y] = max(f[x][y], dp(a, b, matrix) + 1);
			}
		}
		return f[x][y];
	}

	int longestIncreasingPath(vector<vector<int>>& matrix) {
		if (matrix.empty()) return 0;
		n = matrix.size(), m = matrix[0].size();
		f = vector<vector<int>>(n, vector<int>(m, -1));
		int res = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				res = max(res, dp(i, j, matrix));
			}
		}
		return res;
	}
};