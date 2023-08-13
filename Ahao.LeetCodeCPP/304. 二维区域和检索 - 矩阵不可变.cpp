#include<vector>
using namespace std;


/*
304. 二维区域和检索 - 矩阵不可变

给定一个二维矩阵 matrix，以下类型的多个请求：

计算其子矩形范围内元素的总和，该子矩阵的 左上角 为 (row1, col1) ，右下角 为 (row2, col2) 。
实现 NumMatrix 类：

NumMatrix(int[][] matrix) 给定整数矩阵 matrix 进行初始化
int sumRegion(int row1, int col1, int row2, int col2) 返回 左上角 (row1, col1) 、右下角 (row2, col2) 所描述的子矩阵的元素 总和 。
*/
class NumMatrix {
public:
	vector<vector<int>> s;

	NumMatrix(vector<vector<int>>& matrix) {
		if (matrix.empty() || matrix[0].empty()) return;
		s = vector<vector<int>>(matrix.size() + 1, vector<int>(matrix[0].size() + 1));
		for (int i = 1; i <= matrix.size(); i++)
		{
			for (int j = 1; j <= matrix[0].size(); j++)
				s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + matrix[i - 1][j - 1];
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		++row1, ++col1, ++row2, ++col2;
		return s[row2][col2] - s[row1 - 1][col2] - s[row2][col1 - 1] + s[row1 - 1][col1 - 1];
	}
};