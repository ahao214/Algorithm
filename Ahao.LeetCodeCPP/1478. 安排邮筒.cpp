#include<vector>
#include <algorithm>

using namespace std;


/*
1478. 安排邮筒
给你一个房屋数组houses 和一个整数 k ，其中 houses[i] 是第 i 栋房子在一条街上的位置，现需要在这条街上安排 k 个邮筒。

请你返回每栋房子与离它最近的邮筒之间的距离的 最小 总和。

答案保证在 32 位有符号整数范围以内。
*/
class Solution {
public:
	int minDistance(vector<int>& houses, int k) {
		sort(houses.begin(), houses.end());
		int n = houses.size();
		vector<vector<int>> f(n, vector<int>(k + 1));
		vector<vector<int>> cost(n, vector<int>(n));

		for (int i = 0; i < n; i++)
			for (int j = i; j < n; j++)
				for (int r = i; r <= j; r++)
					cost[i][j] += abs(houses[r] - houses[i + (j - i + 1) / 2]);

		for (int i = 0; i < n; i++) f[i][0] = 1e8;
		for (int i = 1; i < n; i++)
		{
			for (int j = 1; j <= k; j++)
			{
				f[i][j] = 1e8;
				for (int r = 0; r <= i; r++)
				{
					int t = 0;
					if (r) t = f[r - 1][j - 1];
					f[i][j] = min(f[i][j], t + cost[r][i]);
				}
			}
		}

		return f[n - 1][k];
	}
};