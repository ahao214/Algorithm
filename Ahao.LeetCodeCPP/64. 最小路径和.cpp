using namespace std;

#include<vector>


class Solution {
	/*
	64. ��С·����
	����һ�������Ǹ������� m x n ���� grid �����ҳ�һ�������Ͻǵ����½ǵ�·����ʹ��·���ϵ������ܺ�Ϊ��С��

	˵����ÿ��ֻ�����»��������ƶ�һ����
	*/
public:
	/*
	Times:O(m*n)
	Space:O(m*n)
	*/
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size(), n = grid[0].size();
		vector<vector<int>> f(m, vector<int>(n, INT_MAX));
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (!i && !j) f[i][j] = grid[i][j];
				else
				{
					if (i) f[i][j] = min(f[i][j], f[i - 1][j] + grid[i][j]);
					if (j) f[i][j] = min(f[i][j], f[i][j - 1] + grid[i][j]);
				}
			}
		}
		return f[m - 1][n - 1];
	}

}