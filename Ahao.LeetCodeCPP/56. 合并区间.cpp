using namespace std;
#include<vector>
#include<algorithm>

class Solution {
	/*
	56. 合并区间
	以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。
	*/
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> ans;
		sort(intervals.begin(), intervals.end());
		int start = intervals[0][0], end = intervals[0][1];
		for (int i = 1; i < intervals.size(); i++)
		{
			if (intervals[i][0] > end)
			{
				ans.push_back({ start,end });
				start = intervals[i][0];
				end = intervals[i][1];
			}
			else
			{
				end = max(end, intervals[i][1]);
			}
		}
		ans.push_back({ start,end });
		return ans;
	}
};