#include<vector>
using namespace std;


/*
304. ��ά����ͼ��� - ���󲻿ɱ�

����һ����ά���� matrix���������͵Ķ������

�������Ӿ��η�Χ��Ԫ�ص��ܺͣ����Ӿ���� ���Ͻ� Ϊ (row1, col1) �����½� Ϊ (row2, col2) ��
ʵ�� NumMatrix �ࣺ

NumMatrix(int[][] matrix) ������������ matrix ���г�ʼ��
int sumRegion(int row1, int col1, int row2, int col2) ���� ���Ͻ� (row1, col1) �����½� (row2, col2) ���������Ӿ����Ԫ�� �ܺ� ��
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