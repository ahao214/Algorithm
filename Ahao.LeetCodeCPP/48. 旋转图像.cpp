using namespace std;
#include<vector>



/*
48. ��תͼ��
����һ�� n �� n �Ķ�ά���� matrix ��ʾһ��ͼ�����㽫ͼ��˳ʱ����ת 90 �ȡ�

������� ԭ�� ��תͼ������ζ������Ҫֱ���޸�����Ķ�ά�����벻Ҫ ʹ����һ����������תͼ��
*/
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		//б45�����ֽ���
		for (int i = 0; i < matrix.size(); i++)
			for (int j = 0; j < i; j++)
				swap(matrix[i][j], matrix[j][i]);

		for (int i = 0; i < matrix.size(); i++)
			for (int j = 0, k = matrix[i].size() - 1; j < k; j++, k--)
				swap(matrix[i][j], matrix[i][k]);
	}
};


class Solution {
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

