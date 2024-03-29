#include<vector>
#include <algorithm>

using namespace std;


/*
1288. 删除被覆盖区间
给你一个区间列表，请你删除列表中被其他区间所覆盖的区间。

只有当 c <= a 且 b <= d 时，我们才认为区间 [a,b) 被区间 [c,d) 覆盖。

在完成所有删除操作后，请你返回列表中剩余区间的数目。
*/
class Solution {
public:
	int removeCoveredIntervals(vector<vector<int>>& intervals) {
		auto comp = [&](vector<int>& a, vector<int>& b)
		{
			if (a[0] == b[0])
				return a[1] > b[1];
			return a[0] < b[0];
		};
		sort(intervals.begin(), intervals.end(), comp);
		int cnt = 0;
		int cur = 0, prev = 0;
		for (auto interval : intervals)
		{
			cur = interval[1];
			if (cur > prev)
			{
				cnt++;
				prev = cur;
			}
		}
		return cnt;
	}
};
