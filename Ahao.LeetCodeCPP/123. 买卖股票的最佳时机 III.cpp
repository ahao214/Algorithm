#include<vector>

using namespace std;


/*
122. 买卖股票的最佳时机 II

给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。

在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。

返回 你能获得的 最大 利润 。
*/


class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		vector<int> left(n), right(n);
		for (int i = 1, minPrice = prices[0]; i < n; i++)
		{
			left[i] = max(left[i - 1], prices[i] - minPrice);
			minPrice = min(minPrice, prices[i]);
		}

		for (int i = n - 2, maxPrice = prices[n - 1]; i >= 0; i--)
		{
			right[i] = max(right[i + 1], maxPrice - prices[i]);
			maxPrice = max(maxPrice, prices[i]);
		}

		int res = 0;
		for (int i = 0; i < n; i++)
			res = max(res, left[i] + right[i]);
		return res;
	}
};



class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		int buy1 = -prices[0], sell1 = 0;
		int buy2 = -prices[0], sell2 = 0;
		for (int i = 1; i < n; ++i) {
			buy1 = max(buy1, -prices[i]);
			sell1 = max(sell1, buy1 + prices[i]);
			buy2 = max(buy2, sell1 - prices[i]);
			sell2 = max(sell2, buy2 + prices[i]);
		}
		return sell2;
	}
};
