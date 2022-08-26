#include<vector>
#include<set>
#include<algorithm>

using namespace std;


/*
1847. 最近的房间
一个酒店里有 n 个房间，这些房间用二维整数数组 rooms 表示，其中 rooms[i] = [roomIdi, sizei] 表示有一个房间号为 roomIdi 的房间且它的面积为 sizei 。每一个房间号 roomIdi 保证是 独一无二 的。

同时给你 k 个查询，用二维数组 queries 表示，其中 queries[j] = [preferredj, minSizej] 。第 j 个查询的答案是满足如下条件的房间 id ：

房间的面积 至少 为 minSizej ，且
abs(id - preferredj) 的值 最小 ，其中 abs(x) 是 x 的绝对值。
如果差的绝对值有 相等 的，选择 最小 的 id 。如果 没有满足条件的房间 ，答案为 -1 。

请你返回长度为 k 的数组 answer ，其中 answer[j] 为第 j 个查询的结果。
*/
class Solution {
public:
	struct Query {
		int id, p, m;
		bool operator < (const Query& t)const {
			return m < t.m;
		}
	};

	vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
		int n = queries.size();
		vector<Query> q;
		for (int i = 0; i < n; i++)
			q.push_back({ i,queries[i][0],queries[i][1] });
		sort(q.begin(), q.end());
		sort(rooms.begin(), rooms.end(), [](vector<int>& a, vector<int>& b)
			{
				return a[1] < b[1];
			});
		const int INF = 1e9;
		vector<int> res(n);
		set<int> hs{ -INF,INF };
		for (int i = n - 1, j = rooms.size() - 1; i >= 0; i--)
		{
			while (j >= 0 && rooms[j][1] >= q[i].m)
				hs.insert(rooms[j--][0]);
			int p = q[i].p, id = q[i].id;
			auto k = hs.lower_bound(p);
			auto u = k;
			--u;
			if (p - *u <= *k - p)
				res[id] = *u;
			else
				res[id] = *k;
			if (abs(res[id]) == INF)
				res[id] = -1;
		}
		return res;
	}

};