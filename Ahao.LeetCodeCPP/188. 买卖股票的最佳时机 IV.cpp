#include<vector>
#include <algorithm>

using namespace std;


/*
188. 买卖股票的最佳时机 IV
*/
class Solution {
	int n;
public:
	int maxProfit(int k, vector<int>& prices)
	{
		n = prices.size();
		prices.insert(prices.begin(), 0);
		int left = 0, right = *max_element(prices.begin(), prices.end());

		while (left < right)
		{
			int fee = left + (right - left) / 2;
			if (helper(prices, fee)[1] > k)
				left = fee + 1;
			else
				right = fee;
		}
		return helper(prices, left)[0] + left * k;
	}

	vector<int> helper(vector<int>& prices, int fee)
	{
		vector<int>sold(n + 1, 0);
		vector<int>hold(n + 1, 0);
		sold[0] = 0;
		hold[0] = INT_MIN / 2;
		int count0 = 0;
		int count1 = 0;

		for (int i = 1; i <= n; i++)
		{
			if (hold[i - 1] + prices[i] > sold[i - 1])
			{
				sold[i] = hold[i - 1] + prices[i];
				count0 = count1 + 1;
			}
			else
				sold[i] = sold[i - 1];

			if (sold[i - 1] - prices[i] - fee > hold[i - 1])
			{
				hold[i] = sold[i - 1] - prices[i] - fee;
				count1 = count0;
			}
			else
				hold[i] = hold[i - 1];
		}
		return { sold[n], count0 };
	}
};




/*
188. 买卖股票的最佳时机 IV

给定一个整数数组 prices ，它的第 i 个元素 prices[i] 是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
*/
class Solution {
	int f[1010][110][2];
public:
	int maxProfit(int k, vector<int>& prices) {
		int n = prices.size();
		memset(f, -0x3f, sizeof(f));
		for (int i = 0; i <= n; i++) {
			f[i][0][0] = 0;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= k; j++) {
				f[i][j][0] = max(f[i - 1][j][0], f[i - 1][j][1] + prices[i - 1]);
				f[i][j][1] = max(f[i - 1][j][1], f[i - 1][j - 1][0] - prices[i - 1]);
			}
		}
		int res = 0;
		for (int i = 0; i <= k; i++)
			res = max(res, f[n][i][0]);
		return res;
	}
};


class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		if (prices.empty()) {
			return 0;
		}

		int n = prices.size();
		k = min(k, n / 2);
		vector<int> buy(k + 1);
		vector<int> sell(k + 1);

		buy[0] = -prices[0];
		sell[0] = 0;
		for (int i = 1; i <= k; ++i) {
			buy[i] = sell[i] = INT_MIN / 2;
		}

		for (int i = 1; i < n; ++i) {
			buy[0] = max(buy[0], sell[0] - prices[i]);
			for (int j = 1; j <= k; ++j) {
				buy[j] = max(buy[j], sell[j] - prices[i]);
				sell[j] = max(sell[j], buy[j - 1] + prices[i]);
			}
		}

		return *max_element(sell.begin(), sell.end());
	}
};



class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		if (prices.empty()) {
			return 0;
		}

		int n = prices.size();
		k = min(k, n / 2);
		vector<vector<int>> buy(n, vector<int>(k + 1));
		vector<vector<int>> sell(n, vector<int>(k + 1));

		buy[0][0] = -prices[0];
		sell[0][0] = 0;
		for (int i = 1; i <= k; ++i) {
			buy[0][i] = sell[0][i] = INT_MIN / 2;
		}

		for (int i = 1; i < n; ++i) {
			buy[i][0] = max(buy[i - 1][0], sell[i - 1][0] - prices[i]);
			for (int j = 1; j <= k; ++j) {
				buy[i][j] = max(buy[i - 1][j], sell[i - 1][j] - prices[i]);
				sell[i][j] = max(sell[i - 1][j], buy[i - 1][j - 1] + prices[i]);
			}
		}

		return *max_element(sell[n - 1].begin(), sell[n - 1].end());
	}
};
