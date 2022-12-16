#include<vector>

using namespace std;

/*
74. ������ά����
��дһ����Ч���㷨���ж� m x n �����У��Ƿ����һ��Ŀ��ֵ���þ�������������ԣ�

ÿ���е����������Ұ��������С�
ÿ�еĵ�һ����������ǰһ�е����һ��������
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
74. ������ά����
��дһ����Ч���㷨���ж� m x n �����У��Ƿ����һ��Ŀ��ֵ���þ�������������ԣ�

ÿ���е����������Ұ��������С�
ÿ�еĵ�һ����������ǰһ�е����һ��������
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