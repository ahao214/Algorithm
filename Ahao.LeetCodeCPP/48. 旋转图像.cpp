using namespace std;
#include<vector>


class Solution {
	/*
	48. 旋转图像
	给定一个 n × n 的二维矩阵 matrix 表示一个图像。
	请你将图像顺时针旋转 90 度。

	你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。
	请不要 使用另一个矩阵来旋转图像。
	*/
public:
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();
		//按左对角线反转
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < i; j++)
				swap(matrix[i][j], matrix[j][i]);
		}

		//左右进行翻转
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n / 2; j++)
				swap(matrix[i][j], matrix[i][n - j - 1]);
		}
	}
};

