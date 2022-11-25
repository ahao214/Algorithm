#include<vector>

using namespace std;


/*
1380. 矩阵中的幸运数
给你一个 m * n 的矩阵，矩阵中的数字 各不相同 。请你按 任意 顺序返回矩阵中的所有幸运数。

幸运数是指矩阵中满足同时下列两个条件的元素：

在同一行的所有元素中最小
在同一列的所有元素中最大
*/
class Solution {
public:
	vector<int> luckyNumbers(vector<vector<int>>& matrix) {
		vector<int> res;
		int n = matrix.size(), m = matrix[0].size();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				bool flag = true;
				for (int k = 0; k < m; k++)
				{
					if (matrix[i][j] > matrix[i][k])
					{
						flag = false;
						break;
					}
				}
				for (int k = 0; k < n; k++)
				{
					if (matrix[i][j] < matrix[k][j])
					{
						flag = false;
						break;
					}
				}
				if (flag)
					res.push_back(matrix[i][j]);
			}
		}
		return res;
	}
};
