#include<vector>
#include<unordered_map>
#include <algorithm>

using namespace std;


/*
1782. 统计点对的数目

给你一个无向图，无向图由整数 n  ，表示图中节点的数目，和 edges 组成，其中 edges[i] = [ui, vi] 表示 ui 和 vi 之间有一条无向边。同时给你一个代表查询的整数数组 queries 。

第 j 个查询的答案是满足如下条件的点对 (a, b) 的数目：

a < b
cnt 是与 a 或者 b 相连的边的数目，且 cnt 严格大于 queries[j] 。
请你返回一个数组 answers ，其中 answers.length == queries.length 且 answers[j] 是第 j 个查询的答案。

请注意，图中可能会有 重复边 。
*/
class Solution {
public:
	vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
		vector<int> d(n + 1);
			unordered_map<int, int> cnt;
		for (auto& e : edges)
		{
			int a = e[0], b = e[1];
			if (a > b) swap(a, b);
			cnt[a * 100000 + b]++;
			d[a]++, d[b]++;
		}
		vector<int> ds(d.begin() + 1, d.end());
		sort(ds.begin(), ds.end());

		vector<int> res;
		for (auto& q : queries)
		{
			int s1 = 0, s2 = 0, s3 = 0;
			for (auto [k, v] : cnt)
			{
				int a = k / 100000, b = k % 10000;
				if (d[a] + d[b] - v > q) s1++;
				if (d[a] + d[b] > q) s2++;
			}
			for (int i = n - 1, j = 0; i > j; i--)
			{
				while (j < i && ds[i] + ds[j] <= q) j++;
				if (j < i && ds[i] + ds[j] > q) s3 += i - j;
			}
			res.push_back(s1 + s3 - s2);
		}
		return res;
	}
};



class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vector<int> degree(n);
        unordered_map<int, int> cnt;
        for (auto edge : edges) {
            int x = edge[0] - 1, y = edge[1] - 1;
            if (x > y) {
                swap(x, y);
            }
            degree[x]++;
            degree[y]++;
            cnt[x * n + y]++;
        }

        vector<int> arr = degree;
        vector<int> ans;
        sort(arr.begin(), arr.end());
        for (int bound : queries) {
            int total = 0;
            for (int i = 0; i < n; i++) {
                int j = upper_bound(arr.begin() + i + 1, arr.end(), bound - arr[i]) - arr.begin();
                total += n - j;
            }
            for (auto& [val, freq] : cnt) {
                int x = val / n;
                int y = val % n;
                if (degree[x] + degree[y] > bound && degree[x] + degree[y] - freq <= bound) {
                    total--;
                }
            }
            ans.emplace_back(total);
        }

        return ans;
    }
};




