#include<vector>
#include <algorithm>

using namespace std;



/*
1626. ��ì�ܵ�������
����������ӵľ������ڼ��������Ľ��������������һ֧����÷���ߵ���ӡ���ӵĵ÷��������������Ա�ķ��� �ܺ� ��

Ȼ��������е�ì�ܻ�������Ա�ķ��ӣ����Ա���ѡ��һ֧ û��ì�� ����ӡ����һ�������С��Ա�ķ��� �ϸ���� һ������ϴ����Ա�������ì�ܡ�ͬ����Ա֮�䲻�ᷢ��ì�ܡ�

���������б� scores �� ages������ÿ�� scores[i] �� ages[i] ��ʾ�� i ����Ա�ķ��������䡣���㷵�� ���п��ܵ���ì������е÷������֧�ķ���
*/
class Solution {
public:
	int bestTeamScore(vector<int>& scores, vector<int>& ages) {
		int n = scores.size();
		vector<pair<int, int>> q(n);
		for (int i = 0; i < n; i++)
			q[i] = { ages[i],scores[i] };
		sort(q.begin(), q.end());
		vector<int> f(n);

		int res = 0;
		for (int i = 0; i < n; i++)
		{
			f[i] = q[i].second;
			for (int j = 0; j < i; j++)
			{
				if (q[i].second >= q[j].second)
					f[i] = max(f[i], f[j] + q[i].second);
			}
			res = max(res, f[i]);
		}
		return res;
	}
};
