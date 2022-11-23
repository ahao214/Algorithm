#include<vector>
#include <queue>
#include <unordered_map>

using namespace std;


/*
1488. 避免洪水泛滥
你的国家有无数个湖泊，所有湖泊一开始都是空的。当第 n 个湖泊下雨的时候，如果第 n 个湖泊是空的，那么它就会装满水，否则这个湖泊会发生洪水。你的目标是避免任意一个湖泊发生洪水。

给你一个整数数组 rains ，其中：

rains[i] > 0 表示第 i 天时，第 rains[i] 个湖泊会下雨。
rains[i] == 0 表示第 i 天没有湖泊会下雨，你可以选择 一个 湖泊并 抽干 这个湖泊的水。
请返回一个数组 ans ，满足：

ans.length == rains.length
如果 rains[i] > 0 ，那么ans[i] == -1 。
如果 rains[i] == 0 ，ans[i] 是你第 i 天选择抽干的湖泊。
如果有多种可行解，请返回它们中的 任意一个 。如果没办法阻止洪水，请返回一个 空的数组 。

请注意，如果你选择抽干一个装满水的湖泊，它会变成一个空的湖泊。但如果你选择抽干一个空的湖泊，那么将无事发生（详情请看示例 4）。
*/
class Solution {
public:
	vector<int> avoidFlood(vector<int>& rains) {
		int n = rains.size();
		vector<int> next(n, n + 1);
		unordered_map<int, int> tm;
		for (int i = n - 1; i >= 0; i--)
		{
			int r = rains[i];
			if (r)
			{
				if (tm.count(r)) next[i] = tm[r];
				tm[r] = i;
			}
		}

		typedef pair<int, int> PII;
		priority_queue<PII, vector<PII>, greater<PII>> heap;
		unordered_map<int, bool> st;

		vector<int> res;
		for (int i = 0; i < n; i++)
		{
			int r = rains[i];
			if (r)
			{
				if (st[r]) return {};
				st[r] = true;
				heap.push({ next[i],r });
				res.push_back(-1);
			}
			else {
				if (heap.empty()) res.push_back(1);
				else {
					auto t = heap.top();
					heap.pop();
					st[t.second] = false;
					res.push_back(t.second);
				}
			}
		}
		return res;
	}
};