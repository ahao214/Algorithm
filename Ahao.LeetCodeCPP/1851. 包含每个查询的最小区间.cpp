#include<vector>
#include<algorithm>
#include<queue>
#include <numeric>


using namespace std;


/*
1851. 包含每个查询的最小区间

给你一个二维整数数组 intervals ，其中 intervals[i] = [lefti, righti] 表示第 i 个区间开始于 lefti 、结束于 righti（包含两侧取值，闭区间）。区间的 长度 定义为区间中包含的整数数目，更正式地表达是 righti - lefti + 1 。

再给你一个整数数组 queries 。第 j 个查询的答案是满足 lefti <= queries[j] <= righti 的 长度最小区间 i 的长度 。如果不存在这样的区间，那么答案是 -1 。

以数组形式返回对应查询的所有答案。
*/
class Solution {
public:
	vector<int> xs, p, w;
	int find(int x)
	{
		if (p[x] != x) p[x] = find(p[x]);
		return p[x];
	}

	int get(int x)
	{
		return lower_bound(xs.begin(), xs.end(), x) - xs.begin();
	}

	vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
		for (auto& s : intervals)
			xs.push_back(s[0]), xs.push_back(s[1]);

		for (auto x : queries) xs.push_back(x);
		sort(xs.begin(), xs.end());
		xs.erase(unique(xs.begin(), xs.end()), xs.end());

		int n = xs.size();
		p.resize(n + 1), w.resize(n + 1, -1);
		for (int i = 0; i < n + 1; i++)
			p[i] = i;

		sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b)
			{
				return a[1] - a[0] < b[1] - b[0];
			});

		for (auto& s : intervals)
		{
			int left = get(s[0]), right = get(s[1]), len = s[1] - s[0] + 1;
			while (find(left) <= right)
			{
				left = find(left);
				w[left] = len;
				p[left] = left + 1;
			}
		}

		vector<int> res;
		for (auto x : queries)
			res.push_back(w[get(x)]);
		return res;
	}

};




class Solution {
public:
	vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
		vector<int> qindex(queries.size());
		iota(qindex.begin(), qindex.end(), 0);
		sort(qindex.begin(), qindex.end(), [&](int i, int j) -> bool {
			return queries[i] < queries[j];
			});
		sort(intervals.begin(), intervals.end(), [](const vector<int>& it1, const vector<int>& it2) -> bool {
			return it1[0] < it2[0];
			});
		priority_queue<vector<int>> pq;
		vector<int> res(queries.size(), -1);
		int i = 0;
		for (auto qi : qindex) {
			while (i < intervals.size() && intervals[i][0] <= queries[qi]) {
				int l = intervals[i][1] - intervals[i][0] + 1;
				pq.push({ -l, intervals[i][0], intervals[i][1] });
				i++;
			}
			while (!pq.empty() && pq.top()[2] < queries[qi]) {
				pq.pop();
			}
			if (!pq.empty()) {
				res[qi] = -pq.top()[0];
			}
		}
		return res;
	}
};
