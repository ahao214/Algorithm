#include<vector>
#include<algorithm>

using namespace std;


/*
1840. 最高建筑高度
在一座城市里，你需要建 n 栋新的建筑。这些新的建筑会从 1 到 n 编号排成一列。

这座城市对这些新建筑有一些规定：

每栋建筑的高度必须是一个非负整数。
第一栋建筑的高度 必须 是 0 。
任意两栋相邻建筑的高度差 不能超过  1 。
除此以外，某些建筑还有额外的最高高度限制。这些限制会以二维整数数组 restrictions 的形式给出，其中 restrictions[i] = [idi, maxHeighti] ，表示建筑 idi 的高度 不能超过 maxHeighti 。

题目保证每栋建筑在 restrictions 中 至多出现一次 ，同时建筑 1 不会 出现在 restrictions 中。

请你返回 最高 建筑能达到的 最高高度 。
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