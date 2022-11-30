using namespace std;
#include<vector>

/*
57. ��������
����һ�� ���ص��� ������������ʼ�˵�����������б�

���б��в���һ���µ����䣬
����Ҫȷ���б��е�������Ȼ�����Ҳ��ص�������б�Ҫ�Ļ������Ժϲ����䣩��
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