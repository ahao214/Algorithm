#include<vector>
#include<algorithm>

using namespace std;



/*
2054. 两个最好的不重叠活动
给你一个下标从 0 开始的二维整数数组 events ，其中 events[i] = [startTimei, endTimei, valuei] 。第 i 个活动开始于 startTimei ，结束于 endTimei ，如果你参加这个活动，那么你可以得到价值 valuei 。你 最多 可以参加 两个时间不重叠 活动，使得它们的价值之和 最大 。

请你返回价值之和的 最大值 。

注意，活动的开始时间和结束时间是 包括 在活动时间内的，也就是说，你不能参加两个活动且它们之一的开始时间等于另一个活动的结束时间。更具体的，如果你参加一个活动，且结束时间为 t ，那么下一个活动必须在 t + 1 或之后的时间开始。
*/
class Solution {
public:
	int maxTwoEvents(vector<vector<int>>& events) {
		int n = events.size();
		vector<int> p(n);
		for (int i = 0; i < n; i++) p[i] = i;
		sort(p.begin(), p.end(), [&](int a, int b) {
			return events[a][1] < events[b][1];
			});

		vector<int> f(n);
		f[0] = events[p[0]][2];
		for (int i = 1; i < n; i++)
			f[i] = max(f[i - 1], events[p[i]][2]);

		int res = 0;
		for (auto& t : events)
		{
			int left = 0, right = n - 1;
			while (left < right)
			{
				int mid = (left + right + 1) >> 1;
				if (events[p[mid]][1] < t[0]) left = mid;
				else right = mid - 1;
			}
			int s = t[2];
			if (events[p[right]][1] < t[0])
				s += f[right];
			res = max(res, s);
		}
		return res;
	}
};

