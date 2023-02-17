#include<vector>

using namespace std;

/*
840. �����еĻ÷�

3 x 3 �Ļ÷���һ������� �� 1 �� 9  �Ĳ�ͬ���ֵ� 3 x 3 ��������ÿ�У�ÿ���Լ������Խ����ϵĸ���֮�Ͷ���ȡ�

����һ����������ɵ�row x col �� grid�������ж��ٸ� 3 �� 3 �� ���÷��� �Ӿ��󣿣�ÿ���Ӿ����������ģ���


ʾ�� 1��

����: grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]
���: 1
����:
������Ӿ�����һ�� 3 x 3 �Ļ÷���

����һ�����ǣ�

�ܵ���˵���ڱ�ʾ���������ľ�����ֻ��һ�� 3 x 3 �Ļ÷��Ӿ���
ʾ�� 2:

���: grid = [[8]]
����: 0


��ʾ:

row == grid.length
col == grid[i].length
1 <= row, col <= 10
0 <= grid[i][j] <= 15
*/

class Solution {
public:
	vector<vector<int>> g;
	bool check(int x, int y)
	{
		bool st[10] = { 0 };
		for (int i = x; i < x + 3; i++)
		{
			for (int j = y; j < y + 3; j++)
			{
				int t = g[i][j];
				if (t < 1 || t > 9) return false;
				if (st[t]) return false;
				st[t] = true;
			}
		}

		for (int i = 0; i < 3; i++)
		{
			if (g[x + i][y] + g[x + i][y + 1] + g[x + i][y + 2] != 15) return false;
			if (g[x][y + i] + g[x + 1][y + i] + g[x + 2][y + i] != 15) return false;
		}
		//�Խ���
		if (g[x][y] + g[x + 1][y + 1] + g[x + 2][y + 2] != 15) return false;
		if (g[x + 2][y] + g[x + 1][y + 1] + g[x][y + 2] != 15) return false;
		return true;
	}

	int numMagicSquaresInside(vector<vector<int>>& grid) {
		g = grid;
		int res = 0;
		int m = grid.size(), n = grid[0].size();
		for (int i = 0; i + 3 <= m; i++)
			for (int j = 0; j + 3 <= n; j++)
				if (check(i, j))
					res++;
		return res;
	}
};

