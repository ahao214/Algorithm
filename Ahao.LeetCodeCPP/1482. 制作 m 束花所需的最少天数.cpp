#include<vector>
#include <algorithm>

using namespace std;


/*
1482. 制作 m 束花所需的最少天数
给你一个整数数组 bloomDay，以及两个整数 m 和 k 。

现需要制作 m 束花。制作花束时，需要使用花园中 相邻的 k 朵花 。

花园中有 n 朵花，第 i 朵花会在 bloomDay[i] 时盛开，恰好 可以用于 一束 花中。

请你返回从花园中摘 m 束花需要等待的最少的天数。如果不能摘到 m 束花则返回 -1 。
*/
class Solution {
public:
	int get(int l, int r, int k)
	{
		return (r - l + 1) / k;
	}
	int minDays(vector<int>& bloomDay, int m, int k) {
		vector<pair<int, int>> q;

		for (int i = 0; i < bloomDay.size(); i++)
			q.push_back({ bloomDay[i],i + 1 });

		int n = bloomDay.size();
		vector<int> l(n + 2), r(n + 2);
		sort(q.begin(), q.end());
		int sum = 0;
		for (auto x : q)
		{
			int i = x.second;
			if (l[i - 1] && r[i + 1]) {
				sum = sum - get(l[i - 1], i - 1, k) - get(i + 1, r[i + 1], k) + get(l[i - 1], r[i + 1], k);
				r[l[i - 1]] = r[i + 1];
				l[r[i + 1]] = l[i - 1];
			}
			else if (l[i - 1]) {
				sum = sum - get(l[i - 1], i - 1, k) + get(l[i - 1], i, k);
				r[l[i - 1]] = i;
				l[i] = l[i - 1];
			}
			else if (r[i + 1]) {
				sum = sum - get(i + 1, r[i + 1], k) + get(i, r[i + 1], k);
				r[i] = r[i + 1];
				l[r[i + 1]] = i;
			}
			else {
				sum = sum + get(i, i, k);
				r[i] = l[i] = i;
			}
			if (sum >= m) return x.first;
		}
		return -1;
	}
};
