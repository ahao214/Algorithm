#include<vector>
#include <algorithm>

using namespace std;


/*
1288. ɾ������������
����һ�������б�����ɾ���б��б��������������ǵ����䡣

ֻ�е� c <= a �� b <= d ʱ�����ǲ���Ϊ���� [a,b) ������ [c,d) ���ǡ�

���������ɾ�����������㷵���б���ʣ���������Ŀ��
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
