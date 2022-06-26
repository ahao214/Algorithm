#include<string>
#include<vector>

using namespace std;



class Solution {
	/*
	73. 矩阵置零
	给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。
	*/
public:
	/*
	Times:O(n*m)
	Space:O(1)
	*/
	void setZeroes(vector<vector<int>>& matrix) {
		int m = matrix.size(), n = matrix[0].size();
		//标记第一行和第一列是否有0
		bool rowZero = false, colZero = false;

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (matrix[i][j] == 0)
				{
					matrix[0][j] = matrix[i][0] == 0;
					if (i == 0) rowZero = true;
					if (j == 0) colZero = true;
				}
			}
		}
		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < n; j++)
			{
				if (matrix[i][0] == 0 || matrix[0][j] = 0)
					matrix[i][j] = 0;
			}
		}

		//处理第一行和第一列
		for (int i = 0; colZero && i < m; i++) matrix[i][0] = 0;
		for (int j = 0; rowZero && j < n; j++) matrix[0][j] = 0;
	}
};