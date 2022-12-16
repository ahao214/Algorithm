#include<vector>

using namespace std;


/*
240. 搜索二维矩阵 II
*/
//时间O(N+M) 空间O(1)
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int m = matrix.size();
		if (m == 0)
			return false;
		int n = matrix[0].size(), col = 0, row = m - 1;
		while (col < n && row >= 0)
		{
			int val = matrix[row][col];
			if (val == target)
				return true;
			if (val < target)
				col++;
			else
				row--;
		}
		return false;
	}
};


/*
240. 搜索二维矩阵 II
编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：
每行的元素从左到右升序排列。
每列的元素从上到下升序排列。
*/
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty() || matrix[0].empty()) return false;
		int i = 0, j = matrix[0].size() - 1;
		while (i < matrix.size() && j >= 0)
		{
			int t = matrix[i][j];
			if (t == target) return true;
			if (t > target) j--;
			else i++;
		}
		return false;
	}
};
