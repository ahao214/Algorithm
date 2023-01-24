#include<vector>

using namespace std;


/*
1828. 统计一个圆中点的数目

给你一个数组 points ，其中 points[i] = [xi, yi] ，表示第 i 个点在二维平面上的坐标。多个点可能会有 相同 的坐标。

同时给你一个数组 queries ，其中 queries[j] = [xj, yj, rj] ，表示一个圆心在 (xj, yj) 且半径为 rj 的圆。

对于每一个查询 queries[j] ，计算在第 j 个圆 内 点的数目。如果一个点在圆的 边界上 ，我们同样认为它在圆 内 。

请你返回一个数组 answer ，其中 answer[j]是第 j 个查询的答案。
*/
class Solution {
public:
	vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
		vector<int> ans;
		for (auto& q : queries)
		{
			int X = q[0], Y = q[1], R = q[2];
			int cnt = 0;
			for (auto& p : points)
			{
				int x = p[0], y = p[1];
				if ((X - x) * (X - x) + (Y - y) * (Y - y) <= R * R)
					cnt++;
			}
			ans.push_back(cnt);
		}
		return ans;
	}
};


class Solution {
public:
	vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
		int m = points.size(), n = queries.size();
		vector<int> ans(n);
		for (int i = 0; i < n; ++i) {
			int cx = queries[i][0], cy = queries[i][1], cr = queries[i][2];
			for (int j = 0; j < m; ++j) {
				int px = points[j][0], py = points[j][1];
				if ((cx - px) * (cx - px) + (cy - py) * (cy - py) <= cr * cr) {
					++ans[i];
				}
			}
		}
		return ans;
	}
};
