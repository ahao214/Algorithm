#include<vector>

using namespace std;


/*
1030. ����˳�����о���Ԫ��

�����ĸ����� rows ,   cols ,  rCenter �� cCenter ����һ�� rows x cols �ľ������ڵ�Ԫ���ϵ������� (rCenter, cCenter) ��

���ؾ����е����е�Ԫ������꣬������ (rCenter, cCenter) �� ���� ����С������˳���š�����԰� �κ� �����������˳�򷵻ش𰸡�

��Ԫ��(r1, c1) �� (r2, c2) ֮��ľ���Ϊ|r1 - r2| + |c1 - c2|��
*/
class Solution {
public:
	vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
		vector<vector<int>> res(1, { rCenter,cCenter });
		int dx[4] = { 1,1,-1,-1 }, dy[4] = { 1,-1,-1,1 };

		for (int d = 1; ; d++)
		{
			int x = rCenter - d, y = cCenter, cnt = 0;
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < d; j++)
				{
					if (x >= 0 && x < rows && y >= 0 && y < cols)
					{
						res.push_back({ x,y });
						cnt++;
					}
					x += dx[i], y += dy[i];
				}
			}
			if (!cnt)break;
		}

		return res;
	}
};