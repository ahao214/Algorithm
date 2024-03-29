#include<vector>

using namespace std;

/*
74. 搜索二维矩阵
编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

每行中的整数从左到右按升序排列。
每行的第一个整数大于前一行的最后一个整数。
*/
class Solution {
public:
	/*
	Times:O(logM*N)
	Space:O(1)
	*/
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int m = matrix.size(), n = matrix[0].size();
		int left = 0, right = m * n - 1;
		while (left < right)
		{
			int mid = left + (right - left) / 2;
			if (matrix[mid / n][mid % n] >= target) right = mid;
			else
				left = mid + 1;
		}
		return matrix[right / n][right % n] == target;
	}
};



/*
74. 搜索二维矩阵
编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

每行中的整数从左到右按升序排列。
每行的第一个整数大于前一行的最后一个整数。
*/
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty() || matrix[0].empty()) return false;
		int n = matrix.size(), m = matrix[0].size();
		int left = 0, right = n * m - 1;
		while (left < right)
		{
			int mid = (left + right) >> 1;
			if (matrix[mid / m][mid % m] >= target)
				right = mid;
			else
				left = mid + 1;
		}
		return matrix[right / m][right % m] == target;
	}
};