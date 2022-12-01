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




/*
57. 插入区间
给你一个 无重叠的 ，按照区间起始端点排序的区间列表。

在列表中插入一个新的区间，
你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。
*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int left = newInterval[0];
        int right = newInterval[1];
        bool placed = false;
        vector<vector<int>> ans;
        for (const auto& interval : intervals) {
            if (interval[0] > right) {
                // 在插入区间的右侧且无交集
                if (!placed) {
                    ans.push_back({ left, right });
                    placed = true;
                }
                ans.push_back(interval);
            }
            else if (interval[1] < left) {
                // 在插入区间的左侧且无交集
                ans.push_back(interval);
            }
            else {
                // 与插入区间有交集，计算它们的并集
                left = min(left, interval[0]);
                right = max(right, interval[1]);
            }
        }
        if (!placed) {
            ans.push_back({ left, right });
        }
        return ans;
    }
};


