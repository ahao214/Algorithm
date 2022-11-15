#include<vector>

using namespace std;


/*
1463. ժӣ�� II
����һ�� rows x cols �ľ��� grid ����ʾһ��ӣ�ҵء� grid ��ÿ�����ӵ����ֱ�ʾ���ܻ�õ�ӣ����Ŀ��

�������������˰����ռ�ӣ�ң������� 1 �����ϽǸ��� (0,0) ������������ 2 �����ϽǸ��� (0, cols-1) ������

���㰴�����¹��򣬷����������������ռ������ӣ����Ŀ��

�Ӹ��� (i,j) �����������˿����ƶ������� (i+1, j-1)��(i+1, j) ���� (i+1, j+1) ��
��һ�������˾���ĳ������ʱ������Ѹø��������е�ӣ�Ҷ�ժ�ߣ�Ȼ�����λ�û��ɿո��ӣ���û��ӣ�ҵĸ��ӡ�
������������ͬʱ����ͬһ������ʱ��������ֻ��һ������ժ��ӣ�ҡ�
����������������ʱ�̶������ƶ��� grid ���档
�������������Ҫ���� grid �����һ�С�
*/
class Solution {
public:
	int cherryPickup(vector<vector<int>>& grid) {
		int n = grid.size(), m = grid[0].size();
		vector<vector<vector<int>>> f(n, vector<vector<int>>(m, vector<int>(m, -1)));

		f[0][0][m - 1] = grid[0][0] + grid[0][m - 1];
		int res = 0;
		for (int k = 1; k < n; k++)
		{
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < m; j++)
				{
					for (int a = i - 1; a <= i + 1; a++)
					{
						for (int b = j - 1; b <= j + 1; b++)
						{
							if (a < 0 || a >= m || b < 0 || b >= m)continue;
							int t = f[k - 1][a][b];
							if (t == -1) continue;
							if (i == j)
								t += grid[k][i];
							else
								t += grid[k][i] + grid[k][j];
							f[k][i][j] = max(t, f[k][i][j]);
							res = max(res, f[k][i][j]);
						}
					}
				}
			}
		}
		return res;
	}
};