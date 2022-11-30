using namespace std;
#include<vector>

/*
57. 插入区间
给你一个 无重叠的 ，按照区间起始端点排序的区间列表。

在列表中插入一个新的区间，
你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。
*/
class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		vector<vector<int>> ans;
		int n = intervals.size(), i = 0;
		while (i < n && intervals[i][1] < newInterval[0])
		{
			ans.push_back(intervals[i++]);
		}

		if (i < n)
		{
			newInterval[0] = min(intervals[i][0], newInterval[0]);
			while (i < n && intervals[i][0] <= newInterval[1])
			{
				newInterval[1] = max(intervals[i++][1], newInterval[1]);
			}
		}
		ans.push_back(newInterval);
		while (i < n)
		{
			ans.push_back(intervals[i++]);
		}
		return ans;
	}
};