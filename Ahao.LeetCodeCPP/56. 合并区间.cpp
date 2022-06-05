using namespace std;
#include<vector>
#include<algorithm>

class Solution {
	/*
	56. �ϲ�����
	������ intervals ��ʾ���ɸ�����ļ��ϣ����е�������Ϊ intervals[i] = [starti, endi] ������ϲ������ص������䣬������ һ�����ص����������飬��������ǡ�ø��������е��������� ��
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