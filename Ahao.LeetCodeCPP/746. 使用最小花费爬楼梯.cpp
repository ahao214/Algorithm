#include<vector>

using namespace std;



/*
746. 使用最小花费爬楼梯
时间O(N) 空间O(1)
*/

class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		vector<int> dp(cost.size() + 1, 0);
		for (int i = 2; i <= cost.size(); i++)
		{
			dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
		}
		return dp[cost.size()];
	}

	int minCostClimbingStairs(vector<int>& cost) {
		int one = 0, two = 0;
		for (int i = 2; i <= cost.size(); i++)
		{
			int tmp = one;
			one = min(one + cost[i - 1], two + cost[i - 2]);
			two = tmp;
		}
		return one;
	}
};