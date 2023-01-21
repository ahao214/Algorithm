#include<vector>

using namespace std;


/*
1030. 距离顺序排列矩阵单元格

给定四个整数 rows ,   cols ,  rCenter 和 cCenter 。有一个 rows x cols 的矩阵，你在单元格上的坐标是 (rCenter, cCenter) 。

返回矩阵中的所有单元格的坐标，并按与 (rCenter, cCenter) 的 距离 从最小到最大的顺序排。你可以按 任何 满足此条件的顺序返回答案。

单元格(r1, c1) 和 (r2, c2) 之间的距离为|r1 - r2| + |c1 - c2|。
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