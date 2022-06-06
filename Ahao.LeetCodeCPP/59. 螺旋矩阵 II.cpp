using namespace std;

#include<vector>


class Solution {
	/*
	59. �������� II
	����һ�������� n ������һ������ 1 �� n2 ����Ԫ�أ���Ԫ�ذ�˳ʱ��˳���������е� n x n �����ξ��� matrix ��
	*/
public:
	/*
	Times:O(n^2)
	Space:O(1)
	*/
	vector<vector<int>> generateMatrix(int n) {
		int up = 0, down = n - 1, left = 0, right = n - 1;
		int num = 1;
		vector<vector<int>> ans(n, vector<int>(n));
		while (true)
		{
			//����ϱ߽�
			for (int i = left; i <= right; i++) ans[up][i] = num++;
			if (++up > down) break;

			//����ұ߽�
			for (int i = up; i <= down; i++) ans[i][right] = num++;
			if (--right < left) break;

			//����±߽�
			for (int i = right; i >= left; i--) ans[down][i] = num++;
			if (--down < up) break;

			//�����߽�
			for (int i = down; i >= up; i--) ans[i][left] = num++;
			if (++left > right) break;

		}
		return ans;
	}
};