#include<vector>
#include<algorithm>

using namespace std;


/*
1840. ��߽����߶�
��һ�����������Ҫ�� n ���µĽ�������Щ�µĽ������ 1 �� n ����ų�һ�С�

�������ж���Щ�½�����һЩ�涨��

ÿ�������ĸ߶ȱ�����һ���Ǹ�������
��һ�������ĸ߶� ���� �� 0 ��
�����������ڽ����ĸ߶Ȳ� ���ܳ���  1 ��
�������⣬ĳЩ�������ж������߸߶����ơ���Щ���ƻ��Զ�ά�������� restrictions ����ʽ���������� restrictions[i] = [idi, maxHeighti] ����ʾ���� idi �ĸ߶� ���ܳ��� maxHeighti ��

��Ŀ��֤ÿ�������� restrictions �� �������һ�� ��ͬʱ���� 1 ���� ������ restrictions �С�

���㷵�� ��� �����ܴﵽ�� ��߸߶� ��
*/
class Solution {
public:
	int maxBuilding(int n, vector<vector<int>>& restrictions) {
		typedef long long LL;
		restrictions.push_back({ 1,0 });
		sort(restrictions.begin(), restrictions.end());
		if (restrictions.back()[0] != n) restrictions.push_back({ n,n - 1 });
		int m = restrictions.size();
		vector<LL> f(m + 1, INT_MAX), g(m + 1, INT_MAX);
		f[0] = -1;
		for (int i = 1; i < m; i++)
		{
			int x = restrictions[i][0], y = restrictions[i][1];
			f[i] = min(f[i - 1], (LL)y - x);
		}
		for (int i = m - 1; i >= 0; i--)
		{
			int x = restrictions[i][0], y = restrictions[i][1];
			g[i] = min(g[i + 1], (LL)y + x);
		}

		LL res = 0;
		for (int i = 0; i < m; i++)
		{
			int x = restrictions[i][0];
			if (i)
			{
				LL Y = (f[i - 1] + g[i]) / 2;
				LL X = Y - f[i - 1];
				if (X >= restrictions[i - 1][0] && X <= restrictions[i][0])
					res = max(res, Y);
			}
			res = max(res, min(x + f[i], -x + g[i]));
		}
		return res;
	}

};