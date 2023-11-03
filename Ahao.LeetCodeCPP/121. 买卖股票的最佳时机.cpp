#include<vector>

using namespace std;



/*
121. 买卖股票的最佳时机

给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。

你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。

返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
*/
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int minPrice = INT_MIN;
		int profit = 0;
		for (auto p : prices) {
			if (p < minPrice) {
				minPrice = p;
			}
			else {
				profit = max(profit, p - minPrice);
			}
		}
		return profit;
	}
};




class Solution {
public:
	/*
	Times:O(n)
	Space:O(1)
	*/
	int maxProfit(vector<int>& prices) {
		int ans = 0, minPrice = prices[0];
		for (int i = 1; i < prices.size(); i++)
		{
			ans = max(ans, prices[i] - minPrice);
			minPrice = min(minPrice, prices[i]);
		}
		return ans;
	}
};
