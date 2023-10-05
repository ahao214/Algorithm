#include<vector>

using namespace std;

/*
714. ������Ʊ�����ʱ����������

����һ���������� prices������ prices[i]��ʾ�� i ��Ĺ�Ʊ�۸� ������ fee �����˽��׹�Ʊ���������á�

��������޴ε���ɽ��ף�������ÿ�ʽ��׶���Ҫ�������ѡ�������Ѿ�������һ����Ʊ����������֮ǰ��Ͳ����ټ��������Ʊ�ˡ�

���ػ����������ֵ��

ע�⣺�����һ�ʽ���ָ������в�������Ʊ���������̣�ÿ�ʽ�����ֻ��ҪΪ֧��һ�������ѡ�
*/


class Solution {
public:
	int maxProfit(vector<int>& prices, int fee) {
		int n = prices.size();
		vector<vector<int>> dp(n, vector<int>(2));
		dp[0][0] = 0, dp[0][1] = -prices[0];
		for (int i = 1; i < n; ++i) {
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
		}
		return dp[n - 1][0];
	}
};


class Solution {
public:
	int maxProfit(vector<int>& prices, int fee) {
		int n = prices.size();
		int buy = prices[0] + fee;
		int profit = 0;
		for (int i = 1; i < n; ++i) {
			if (prices[i] + fee < buy) {
				buy = prices[i] + fee;
			}
			else if (prices[i] > buy) {
				profit += prices[i] - buy;
				buy = prices[i];
			}
		}
		return profit;
	}
};

