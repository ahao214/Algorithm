#include<vector>

using namespace std;


/*
240. ������ά���� II
*/
//ʱ��O(N+M) �ռ�O(1)
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
