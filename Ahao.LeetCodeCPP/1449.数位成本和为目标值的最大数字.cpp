#include<vector>
#include<string>

using namespace std;



/*
1449. 数位成本和为目标值的最大数字
给你一个整数数组 cost 和一个整数 target 。请你返回满足如下规则可以得到的 最大 整数：

给当前结果添加一个数位（i + 1）的成本为 cost[i] （cost 数组下标从 0 开始）。
总成本必须恰好等于 target 。
添加的数位中没有数字 0 。
由于答案可能会很大，请你以字符串形式返回。

如果按照上述要求无法得到任何整数，请你返回 "0" 。
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




class Solution {
public:
	/*
	1、位数最多
	2、位数相同,字典序最大
	*/
	string largestNumber(vector<int>& cost, int target) {
		vector<vector<int>> f(10, vector<int>(target + 1));

		for (int i = 1; i <= target; i++) f[0][i] = -1e8;
		for (int i = 1; i <= 9; i++)
		{
			for (int j = 0; j <= target; j++)
			{
				f[i][j] = f[i - 1][j];
				if (j >= cost[i - 1])
					f[i][j] = max(f[i][j], f[i][j - cost[i - 1]] + 1);
			}
		}
		if (f[9][target] < 1) return "0";
		string res;
		for (int i = 9, j = target; i; i--)
		{
			while (j >= cost[i - 1] && f[i][j] == f[i][j - cost[i - 1]] + 1);
			{
				res += to_string(i);
				j -= cost[i - 1];
			}
		}
		return res;
	}
};


