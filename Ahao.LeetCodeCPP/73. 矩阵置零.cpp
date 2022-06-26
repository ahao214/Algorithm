#include<string>
#include<vector>

using namespace std;



class Solution {
	/*
	73. ��������
	����һ�� m x n �ľ������һ��Ԫ��Ϊ 0 �����������к��е�����Ԫ�ض���Ϊ 0 ����ʹ�� ԭ�� �㷨��
	*/
public:
	/*
	Times:O(n*m)
	Space:O(1)
	*/
	void setZeroes(vector<vector<int>>& matrix) {
		int m = matrix.size(), n = matrix[0].size();
		//��ǵ�һ�к͵�һ���Ƿ���0
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

		//�����һ�к͵�һ��
		for (int i = 0; colZero && i < m; i++) matrix[i][0] = 0;
		for (int j = 0; rowZero && j < n; j++) matrix[0][j] = 0;
	}
};