#include<vector>

using namespace std;



/*
offer 29 ˳ʱ���ӡ����
*/
class Solution {
public:
	vector<int> printMatrix(vector<vector<int>> matrix) {
		vector<int> ans;
		if (matrix.size() == 0 || matrix[0].size() == 0) {
			return ans;
		}

		int up = 0;
		int down = matrix.size() - 1;
		int left = 0;
		int right = matrix[0].size() - 1;

		while (true) {
			//������
			for (int i = left; i <= right; ++i) {
				ans.push_back(matrix[up][i]);
			}
			up++;
			if (up > down) {
				break;
			}
			//���ϵ���
			for (int i = up; i <= down; ++i) {
				ans.push_back(matrix[i][right]);
			}
			right--;
			if (right < left)
				break;

			//���ҵ���
			for (int i = right; i >= left; --i) {
				ans.push_back(matrix[down][i]);
			}
			down--;
			if (up > down)break;

			//���µ���
			for (int i = down; i >= up; --i) {
				ans.push_back(matrix[i][left]);
			}
			left++;
			if (right < left) break;
		}
		return ans;
	}
};