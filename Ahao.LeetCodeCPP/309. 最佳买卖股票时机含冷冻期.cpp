﻿#include<vector>

using namespace std;


/*
309. 最佳买卖股票时机含冷冻期

给定一个整数数组prices，其中第  prices[i] 表示第 i 天的股票价格 。​

设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:

卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
*/
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty()) return 0;
		int n = prices.size(), INF = 1e8;
		vector<vector<int>> f(n, vector<int>(3, -INF));
		f[0][1] = -prices[0], f[0][0] = 0;
		for (int i = 1; i < n; i++)
		{
			f[i][0] = max(f[i - 1][0], f[i - 1][2]);
			f[i][1] = max(f[i - 1][1], f[i - 1][0] - prices[i]);
			f[i][2] = f[i - 1][1] + prices[i];
		}
		return max(f[n - 1][0], max(f[n - 1][1], f[n - 1][2]));
	}
};