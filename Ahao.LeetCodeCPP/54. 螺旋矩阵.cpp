using namespace std;
#include<vector>

class Solution {
	/*
	54. ��������
	����һ�� m �� n �еľ��� matrix ��
	�밴�� ˳ʱ������˳�� �����ؾ����е�����Ԫ�ء�
	*/
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int m = matrix.size(), n = matrix[0].size();
		//�������ҵı߽�
		int up = 0, down = m - 1, left = 0, right = n - 1;
		vector<int> ans;
		while (true)
		{
			//�ϱ߽�
			for (int i = left; i <= right; i++) ans.push_back(matrix[up][i]);
			if (++up > down) break;

			//�ұ߽�
			for (int i = up; i <= down; i++) ans.push_back(matrix[i][right]);
			if (--right < left) break;

			//�±߽�
			for (int i = right; i >= left; i--) ans.push_back(matrix[down][i]);
			if (--down < up) break;

			//��߽�
			for (int i = down; i >= up; i--) ans.push_back(matrix[i][left]);
			if (++left > right) break;
		}
		return ans;
	}
};