#include<vector>

using namespace std;


/*
1219. 黄金矿工

你要开发一座金矿，地质勘测学家已经探明了这座金矿中的资源分布，并用大小为 m * n 的网格 grid 进行了标注。每个单元格中的整数就表示这一单元格中的黄金数量；如果该单元格是空的，那么就是 0。

为了使收益最大化，矿工需要按以下规则来开采黄金：

每当矿工进入一个单元，就会收集该单元格中的所有黄金。
矿工每次可以从当前位置向上下左右四个方向走。
每个单元格只能被开采（进入）一次。
不得开采（进入）黄金数目为 0 的单元格。
矿工可以从网格中 任意一个 有黄金的单元格出发或者是停止。
*/
class Solution {
public:
	int ans = 0;
	void f(vector<vector<int>>& grid, int x, int y, int num) {
		num += grid[x][y];
		ans = max(ans, num);
		const int dirs[4][2] = {
			{0,1},{0,-1},{-1,0},{1,0}
		};
		int m = grid.size(), n = grid[0].size(), tmp = grid[x][y];
		grid[x][y] = 0;
		for (int i = 0; i < 4; i++) {
			int nx = x + dirs[i][0], ny = y + dirs[i][1];
			if (nx < 0 || nx >= m || ny < 0 || ny >= n || !grid[nx][ny])
				continue;
			f(grid, nx, ny, num);
		}
		grid[x][y] = tmp;
	}

	int getMaximumGold(vector<vector<int>>& grid) {
		int m = grid.size(), n = grid[0].size();
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j]) {
					f(grid, i, j, 0);
				}
			}
		}
		return ans;
	}
};
