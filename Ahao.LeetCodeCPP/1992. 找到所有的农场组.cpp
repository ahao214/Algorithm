#include<vector>

using namespace std;



/*
1992. 找到所有的农场组
给你一个下标从 0 开始，大小为 m x n 的二进制矩阵 land ，其中 0 表示一单位的森林土地，1 表示一单位的农场土地。

为了让农场保持有序，农场土地之间以矩形的 农场组 的形式存在。每一个农场组都 仅 包含农场土地。且题目保证不会有两个农场组相邻，也就是说一个农场组中的任何一块土地都 不会 与另一个农场组的任何一块土地在四个方向上相邻。

land 可以用坐标系统表示，其中 land 左上角坐标为 (0, 0) ，右下角坐标为 (m-1, n-1) 。请你找到所有 农场组 最左上角和最右下角的坐标。一个左上角坐标为 (r1, c1) 且右下角坐标为 (r2, c2) 的 农场组 用长度为 4 的数组 [r1, c1, r2, c2] 表示。

请你返回一个二维数组，它包含若干个长度为 4 的子数组，每个子数组表示 land 中的一个 农场组 。如果没有任何农场组，请你返回一个空数组。可以以 任意顺序 返回所有农场组。
*/
class Solution {
public:
	vector<vector<int>> findFarmland(vector<vector<int>>& land) {
		int n = land.size(), m = land[0].size();
		vector<vector<int>> res;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (land[i][j])
				{
					int x = i, y = j;
					for (int a = i; a < n && land[a][j]; a++)
					{
						for (int b = j; b < m && land[a][b]; b++)
						{
							land[a][b] = 0;
							x = max(x, a), y = max(y, b);
						}
					}
					res.push_back({ i,j,x,y });
				}
			}
		}
		return res;
	}
};


