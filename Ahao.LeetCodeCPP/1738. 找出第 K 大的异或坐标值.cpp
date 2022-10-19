#include<vector>

using namespace std;


/*
1738. �ҳ��� K ����������ֵ
����һ����ά���� matrix ��һ������ k �������СΪ m x n �ɷǸ�������ɡ�

���������� (a, b) �� ֵ ���ɶ��������� 0 <= i <= a < m �� 0 <= j <= b < n ��Ԫ�� matrix[i][j]���±�� 0 ��ʼ������ִ���������õ���

�����ҳ� matrix �����������е� k ���ֵ��k ��ֵ�� 1 ��ʼ��������
*/

const int N = 1000010;
int q[N];

class Solution {
public:
	int kthLargestValue(vector<vector<int>>& matrix, int k) {
		int n = matrix.size(), m = matrix[0].size();
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (i) matrix[i][j] ^= matrix[i - 1][j];
				if (j) matrix[i][j] ^= matrix[i][j - 1];
				if (i && j) matrix[i][j] ^= matrix[i - 1][j - 1];
				q[cnt++] = matrix[i][j];
			}
		}
		k = cnt - k;
		nth_element(q, q + k, q + cnt);
		return q[k];
	}
};