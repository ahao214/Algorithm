using namespace std;

#include<vector>


class Solution {
	/*
	63. ��ͬ·�� II
	һ��������λ��һ�� m x n ��������Ͻ� ����ʼ������ͼ�б��Ϊ ��Start�� ����

	������ÿ��ֻ�����»��������ƶ�һ������������ͼ�ﵽ��������½ǣ�����ͼ�б��Ϊ ��Finish������

	���ڿ������������ϰ����ô�����Ͻǵ����½ǽ����ж�������ͬ��·����

	�����е��ϰ���Ϳ�λ�÷ֱ��� 1 �� 0 ����ʾ��
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