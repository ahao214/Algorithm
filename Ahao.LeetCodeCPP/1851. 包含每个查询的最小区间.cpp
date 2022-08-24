#include<vector>
#include<algorithm>
#include<queue>


using namespace std;


/*
1851. ����ÿ����ѯ����С����
����һ����ά�������� intervals ������ intervals[i] = [lefti, righti] ��ʾ�� i �����俪ʼ�� lefti �������� righti����������ȡֵ�������䣩������� ���� ����Ϊ�����а�����������Ŀ������ʽ�ر���� righti - lefti + 1 ��

�ٸ���һ���������� queries ���� j ����ѯ�Ĵ������� lefti <= queries[j] <= righti �� ������С���� i �ĳ��� ��������������������䣬��ô���� -1 ��

��������ʽ���ض�Ӧ��ѯ�����д𰸡�
*/
class Solution {
public:
	vector<int> xs, p, w;
	int find(int x)
	{
		if (p[x] != x) p[x] = find(p[x]);
		return p[x];
	}

	int get(int x)
	{
		return lower_bound(xs.begin(), xs.end(), x) - xs.begin();
	}

	vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
		for (auto& s : intervals)
			xs.push_back(s[0]), xs.push_back(s[1]);

		for (auto x : queries) xs.push_back(x);
		sort(xs.begin(), xs.end());
		xs.erase(unique(xs.begin(), xs.end()), xs.end());

		int n = xs.size();
		p.resize(n + 1), w.resize(n + 1, -1);
		for (int i = 0; i < n + 1; i++)
			p[i] = i;

		sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b)
			{
				return a[1] - a[0] < b[1] - b[0];
			});

		for (auto& s : intervals)
		{
			int left = get(s[0]), right = get(s[1]), len = s[1] - s[0] + 1;
			while (find(left) <= right)
			{
				left = find(left);
				w[left] = len;
				p[left] = left + 1;
			}
		}

		vector<int> res;
		for (auto x : queries)
			res.push_back(w[get(x)]);
		return res;
	}

};
