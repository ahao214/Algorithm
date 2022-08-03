#include<vector>
#include<string>

using namespace std;


/*
1449.数位成本和为目标值的最大数字
*/
class Solution {
	string dp[5001];
public:
	string largestNumber(vector<int>& cost, int target) {
		cost.insert(cost.begin(), 0);

		for (int c = 1; c <= target; c++)
		{
			dp[c] = "#";
			for (int i = 1; i <= 9; i++)
			{
				if (c < cost[i] || dp[c - cost[i]] == "#") continue;
				string candidate = dp[c - cost[i]] + to_string(i);
				if (candidate.size() > dp[c].size() || candidate.size() == dp[c].size() && candidate > dp[c])
					dp[c] = candidate;
			}
		}
		if (dp[target] == "#")
			return "0";
		else
			return dp[target];
	}
};
