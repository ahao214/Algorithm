#include <vector>

using namespace std;


/*
766. 托普利茨矩阵

给你一个 m x n 的矩阵 matrix 。如果这个矩阵是托普利茨矩阵，返回 true ；否则，返回 false 。

如果矩阵上每一条由左上到右下的对角线上的元素都相同，那么这个矩阵是 托普利茨矩阵 。
*/
class Solution {
public:
	bool isToeplitzMatrix(vector<vector<int>>& matrix) {
		for (int i = 1; i < matrix.size(); i++)
		{
			for (int j = 1; j < matrix[0].size(); j++)
				if (matrix[i][j] != matrix[i - 1][j - 1])
					return false;
		}
		return true;
	}
};
