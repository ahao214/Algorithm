#include<vector>
#include <unordered_map>
#include <queue>

using namespace std;



/*
2493. 将节点分成尽可能多的组
给你一个正整数 n ，表示一个 无向 图中的节点数目，节点编号从 1 到 n 。

同时给你一个二维整数数组 edges ，其中 edges[i] = [ai, bi] 表示节点 ai 和 bi 之间有一条 双向 边。注意给定的图可能是不连通的。

请你将图划分为 m 个组（编号从 1 开始），满足以下要求：

图中每个节点都只属于一个组。
图中每条边连接的两个点 [ai, bi] ，如果 ai 属于编号为 x 的组，bi 属于编号为 y 的组，那么 |y - x| = 1 。
请你返回最多可以将节点分为多少个组（也就是最大的 m ）。如果没办法在给定条件下分组，请你返回 -1 。
*/
class Solution {
	vector<int>next[505];
public:
	int magnificentSets(int n, vector<vector<int>>& edges) {
		for (auto edge : edges) {
			int a = edge[0], b = edge[1];
			next[a].push_back(b);
			next[b].push_back(a);
		}
		unordered_map<int, int>map;
		for (int start = 1; start <= n; start++) {
			int maxDepth = 0;
			int smallestId = INT_MAX;
			vector<int>level(505);
			queue<pair<int, int>> q;
			q.push({ start,1 });
			level[start] = 1;
			while (!q.empty()) {
				auto [cur, d] = q.front();
				q.pop();
				maxDepth = max(maxDepth, d);
				smallestId = min(smallestId, cur);

				for (int nxt : next[cur]) {
					if (level[nxt] == 0) {
						level[nxt] = d + 1;
						q.push({ nxt,d + 1 });
					}
					else if (level[nxt] == d) {
						return -1;
					}
				}
			}
			map[smallestId] = max(map[smallestId], maxDepth);
		}
		int res = 0;
		for (auto [k, v] : map) {
			res += v;
		}
		return res;
	}
};