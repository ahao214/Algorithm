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


/*
240. ������ά���� II
��дһ����Ч���㷨������ m x n ���� matrix �е�һ��Ŀ��ֵ target ���þ�������������ԣ�
ÿ�е�Ԫ�ش������������С�
ÿ�е�Ԫ�ش��ϵ����������С�
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
