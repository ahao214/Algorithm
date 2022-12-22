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




/*
54. ��������
����һ�� m �� n �еľ��� matrix ���밴�� ˳ʱ������˳�� �����ؾ����е�����Ԫ�ء�
*/
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> res;
		if (matrix.empty()) return res;
		int n = matrix.size(), m = matrix[0].size();
		vector<vector<bool>> visited(n, vector<bool>(m));

		int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };

		int x = 0, y = 0, d = 1;
		for (int k = 0; k < n * m; k++)
		{
			res.push_back(matrix[x][y]);
			visited[x][y] = true;
			int a = x + dx[d], b = y + dy[d];
			if (a < 0 || a >= n || b < 0 || b >= m || visited[a][b])
			{
				d = (d + 1) % 4;
				a = x + dx[d], b = y + dy[d];
			}
			x = a, y = b;
		}
		return res;
	}
};