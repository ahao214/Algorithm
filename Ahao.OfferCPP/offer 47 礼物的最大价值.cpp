#include<vector>

using namespace std;


/*
offer 47 ���������ֵ
*/
class Solution {
public:
	int maxValue(vector<vector<int> >& grid) {
		int row = grid.size();
		int col = grid[0].size();
		vector<vector<int>> res(row, vector<int>(col, 0));
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				if (i == 0 && j == 0)
				{
					res[0][0] = grid[0][0];
				}
				else if (i == 0)	//��һ��
				{
					res[i][j] = grid[i][j] + res[i][j - 1];
				}
				else if (j == 0)	//��һ��
				{
					res[i][j] = grid[i][j] + res[i - 1][j];
				}
				else
				{
					res[i][j] = grid[i][j] + max(res[i - 1][j], res[i][j - 1]);
				}
			}
		}
		return res[row - 1][col - 1];
	}
};

