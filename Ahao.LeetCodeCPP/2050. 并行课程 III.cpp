#include<vector>
#include <unordered_map>
#include <functional>

using namespace std;

/*
2050. 并行课程 III

给你一个整数 n ，表示有 n 节课，课程编号从 1 到 n 。同时给你一个二维整数数组 relations ，其中 relations[j] = [prevCoursej, nextCoursej] ，表示课程 prevCoursej 必须在课程 nextCoursej 之前 完成（先修课的关系）。同时给你一个下标从 0 开始的整数数组 time ，其中 time[i] 表示完成第 (i+1) 门课程需要花费的 月份 数。

请你根据以下规则算出完成所有课程所需要的 最少 月份数：

如果一门课的所有先修课都已经完成，你可以在 任意 时间开始这门课程。
你可以 同时 上 任意门课程 。
请你返回完成所有课程所需要的 最少 月份数。

注意：测试数据保证一定可以完成所有课程（也就是先修课的关系构成一个有向无环图）。
*/


class Solution {
public:
	int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
		int mx = 0;
		vector<vector<int>> prev(n + 1);
		for (auto& relation : relations) {
			int x = relation[0], y = relation[1];
			prev[y].emplace_back(x);
		}
		unordered_map<int, int> memo;
		function<int(int)> dp = [&](int i) -> int {
			if (!memo.count(i)) {
				int cur = 0;
				for (int p : prev[i]) {
					cur = max(cur, dp(p));
				}
				cur += time[i - 1];
				memo[i] = cur;
			}
			return memo[i];
		};

		for (int i = 1; i <= n; i++) {
			mx = max(mx, dp(i));
		}
		return mx;
	}
};
