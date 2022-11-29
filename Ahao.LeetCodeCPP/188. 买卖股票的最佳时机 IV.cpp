#include<vector>
#include <algorithm>

using namespace std;


/*
188. ������Ʊ�����ʱ�� IV
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
188. ������Ʊ�����ʱ�� IV
����һ���������� prices �����ĵ� i ��Ԫ�� prices[i] ��һ֧�����Ĺ�Ʊ�ڵ� i ��ļ۸�

���һ���㷨�����������ܻ�ȡ�������������������� k �ʽ��ס�

ע�⣺�㲻��ͬʱ�����ʽ��ף���������ٴι���ǰ���۵�֮ǰ�Ĺ�Ʊ����
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