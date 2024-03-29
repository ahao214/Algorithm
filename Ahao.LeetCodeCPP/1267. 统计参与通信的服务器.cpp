#include<vector>
#include<unordered_map>


using namespace std;

/*
1267. 统计参与通信的服务器

这里有一幅服务器分布图，服务器的位置标识在 m * n 的整数矩阵网格 grid 中，1 表示单元格上有服务器，0 表示没有。

如果两台服务器位于同一行或者同一列，我们就认为它们之间可以进行通信。

请你统计并返回能够与至少一台其他服务器进行通信的服务器的数量。
*/


class Solution {
public:
	int countServers(vector<vector<int>>& grid) {
		int m = grid.size(), n = grid[0].size();
		unordered_map<int, int> rows, cols;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == 1) {
					++rows[i];
					++cols[j];
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == 1 && (rows[i] > 1 || cols[j] > 1)) {
					++ans;
				}
			}
		}
		return ans;
	}
};
