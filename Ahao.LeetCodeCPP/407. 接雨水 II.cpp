#include<vector>
#include <queue>

using namespace std;


/*
407. 接雨水 II

给你一个 m x n 的矩阵，其中的值均为非负整数，代表二维高度图每个单元的高度，请计算图中形状最多能接多少体积的雨水。
*/
class Solution {
public:
	struct Cell {
		int h, x, y;
		bool operator< (const Cell& t)const {
			return h > t.h;
		}
	};
	int trapRainWater(vector<vector<int>>& heightMap) {
		if (heightMap.empty() || heightMap[0].empty()) return 0;
		int n = heightMap.size(), m = heightMap[0].size();
		priority_queue<Cell> heap;
		vector<vector<bool>> st(n, vector<bool>(m));
		for (int i = 0; i < n; i++)
		{
			st[i][0] = st[i][m - 1] = true;
			heap.push({ heightMap[i][0],i,0 });
			heap.push({ heightMap[i][m - 1],i,m - 1 });
		}
		for (int i = 1; i + 1 < m; i++)
		{
			st[0][i] = st[n - 1][i] = true;
			heap.push({ heightMap[0][i],0,i });
			heap.push({ heightMap[n - 1][i],n - 1,i });
		}
		int res = 0;
		int dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 };
		while (heap.size())
		{
			auto t = heap.top();
			heap.pop();
			res += t.h - heightMap[t.x][t.y];

			for (int i = 0; i < 4; i++)
			{
				int x = t.x + dx[i], y = t.y + dy[i];
				if (x >= 0 && x < n && y >= 0 && y < m && !st[x][y])
				{
					heap.push({ max(heightMap[x][y],t.h),x,y });
					st[x][y] = true;
				}
			}
		}
		return res;
	}
};
