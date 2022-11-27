#include<vector>

using namespace std;


/*
1380. �����е�������
����һ�� m * n �ľ��󣬾����е����� ������ͬ �����㰴 ���� ˳�򷵻ؾ����е�������������

��������ָ����������ͬʱ��������������Ԫ�أ�

��ͬһ�е�����Ԫ������С
��ͬһ�е�����Ԫ�������
*/
class Solution {
public:
	vector<int> luckyNumbers(vector<vector<int>>& matrix) {
		vector<int> res;
		int n = matrix.size(), m = matrix[0].size();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				bool flag = true;
				for (int k = 0; k < m; k++)
				{
					if (matrix[i][j] > matrix[i][k])
					{
						flag = false;
						break;
					}
				}
				for (int k = 0; k < n; k++)
				{
					if (matrix[i][j] < matrix[k][j])
					{
						flag = false;
						break;
					}
				}
				if (flag)
					res.push_back(matrix[i][j]);
			}
		}
		return res;
	}
};





/*
1380. �����е�������
����һ�� m * n �ľ��󣬾����е����� ������ͬ �����㰴 ���� ˳�򷵻ؾ����е�������������

��������ָ����������ͬʱ��������������Ԫ�أ�

��ͬһ�е�����Ԫ������С
��ͬһ�е�����Ԫ�������
*/
class Solution {
public:
	vector<int> luckyNumbers(vector<vector<int>>& matrix) {
		int m = matrix.size(), n = matrix[0].size();
		vector<int> row(m, INT_MAX), col(n, INT_MIN);
		vector<int> ans;
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				row[i] = min(row[i], matrix[i][j]);
				col[j] = max(col[j], matrix[i][j]);
			}
		}
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (matrix[i][j] == row[i] && matrix[i][j] == col[j])
				{
					ans.push_back(matrix[i][j]);
				}
			}
		}
		return ans;
	}
};
