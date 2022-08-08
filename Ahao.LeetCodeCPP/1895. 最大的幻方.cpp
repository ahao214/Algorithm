#include<vector>

using namespace std;


/*
1895. ���Ļ÷�
һ�� k x k �� �÷� ָ����һ�� k x k ���������ķ�������ÿһ�С�ÿһ���Լ������Խ��ߵĺ� ȫ����� ���÷��е����� ����Ҫ������ͬ ����Ȼ��ÿ�� 1 x 1 �ķ�����һ���÷���

����һ�� m x n ���������� grid �����㷵�ؾ����� ���÷� �� �ߴ� �����߳� k����
*/
typedef long long LL;
class Solution {
public:
	bool check(vector<vector<int>>& g, int a, int b, int c, int d)
	{
		LL sum = 0;
		for (int i = a; i <= c; i++)
		{
			LL s = 0;
			for (int j = b; j <= d; j++)
				s += g[i][j];
			if (sum && sum != s)return false;
			sum = s;
		}
		for (int i = b; i <= d; i++)
		{
			LL s = 0;
			for (int j = a; j <= c; j++)
			{
				s += g[j][i];
			}
			if (sum != s)return false;
		}

		LL s = 0;
		for (int i = a, j = b; i <= c; i++, j++)
			s += g[i][j];
		if (s != sum) return false;

		s = 0;
		for (int i = a, j = d; i <= c; i++, j--)
			s += g[i][j];
		return s == sum;
	}

	int largestMagicSquare(vector<vector<int>>& grid) {
		int n = grid.size(), m = grid[0].size();
		for (int k = min(n, m); k; k--)
			for (int i = 0; i + k - 1 < n; i++)
				for (int j = 0; j + k - 1 < m; j++)
					if (check(grid, i, j, i + k - 1, j + k - 1))
						return k;
		return 1;
	}

};

