#include<vector>
#include <queue>

using namespace std;



/*
2503. 矩阵查询可获得的最大分数

给你一个大小为 m x n 的整数矩阵 grid 和一个大小为 k 的数组 queries 。

找出一个大小为 k 的数组 answer ，且满足对于每个整数 queres[i] ，你从矩阵 左上角 单元格开始，重复以下过程：

如果 queries[i] 严格 大于你当前所处位置单元格，如果该单元格是第一次访问，则获得 1 分，并且你可以移动到所有 4 个方向（上、下、左、右）上任一 相邻 单元格。
否则，你不能获得任何分，并且结束这一过程。
在过程结束后，answer[i] 是你可以获得的最大分数。注意，对于每个查询，你可以访问同一个单元格 多次 。

返回结果数组 answer 。
*/
using AI3 = array<int, 3>;
class Solution {
	int visited[1000][1000];
public:
	vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
		int m = grid.size();
		int n = grid[0].size();
		vector<pair<int, int>>dir({ {1,0},{-1,0},{0,1},{0,-1} });

		vector<pair<int, int>> qs;
		for (int i = 0; i < queries.size(); i++) {
			qs.push_back({ queries[i],i });
		}
		sort(qs.begin(), qs.end());

		vector<int>res(qs.size());
		priority_queue<AI3, vector<AI3>, greater<>> pq;
		pq.push({ grid[0][0],0,0 });
		visited[0][0] = 1;
		int count = 0;

		for (auto& [q, idx] : qs) {
			while (!pq.empty() && pq.top()[0] < q) {
				int i = pq.top()[1];
				int j = pq.top()[2];
				pq.pop();
				count++;

				for (int k = 0; k < 4; k++) {
					int x = i + dir[k].first;
					int y = j + dir[k].second;
					if (x < 0 || x >= m || y < 0 || y >= n)
						continue;
					if (visited[x][y] == 1)
						continue;
					pq.push({ grid[x][y],x,y });
					visited[x][y] = 1;
				}
			}
			res[idx] = count;
		}
		return res;
	}
};