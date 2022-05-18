using namespace std;
#include<vector>


class Solution {
	/*
	48. ��תͼ��
	����һ�� n �� n �Ķ�ά���� matrix ��ʾһ��ͼ��
	���㽫ͼ��˳ʱ����ת 90 �ȡ�

	������� ԭ�� ��תͼ������ζ������Ҫֱ���޸�����Ķ�ά����
	�벻Ҫ ʹ����һ����������תͼ��
	*/
public:
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();
		//����Խ��߷�ת
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < i; j++)
				swap(matrix[i][j], matrix[j][i]);
		}

		//���ҽ��з�ת
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n / 2; j++)
				swap(matrix[i][j], matrix[i][n - j - 1]);
		}
	}
};

