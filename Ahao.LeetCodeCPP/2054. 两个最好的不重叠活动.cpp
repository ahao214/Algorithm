#include<vector>
#include<algorithm>

using namespace std;



/*
2054. ������õĲ��ص��
����һ���±�� 0 ��ʼ�Ķ�ά�������� events ������ events[i] = [startTimei, endTimei, valuei] ���� i �����ʼ�� startTimei �������� endTimei �������μ���������ô����Եõ���ֵ valuei ���� ��� ���Բμ� ����ʱ�䲻�ص� ���ʹ�����ǵļ�ֵ֮�� ��� ��

���㷵�ؼ�ֵ֮�͵� ���ֵ ��

ע�⣬��Ŀ�ʼʱ��ͽ���ʱ���� ���� �ڻʱ���ڵģ�Ҳ����˵���㲻�ܲμ������������֮һ�Ŀ�ʼʱ�������һ����Ľ���ʱ�䡣������ģ������μ�һ������ҽ���ʱ��Ϊ t ����ô��һ��������� t + 1 ��֮���ʱ�俪ʼ��
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

