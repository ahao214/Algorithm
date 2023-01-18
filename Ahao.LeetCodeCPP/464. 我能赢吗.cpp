#include<vector>
#include<unordered_map>

using namespace std;


/*
464. 我能赢吗

在 "100 game" 这个游戏中，两名玩家轮流选择从 1 到 10 的任意整数，累计整数和，先使得累计整数和 达到或超过  100 的玩家，即为胜者。

如果我们将游戏规则改为 “玩家 不能 重复使用整数” 呢？

例如，两个玩家可以轮流从公共整数池中抽取从 1 到 15 的整数（不放回），直到累计整数和 >= 100。

给定两个整数 maxChoosableInteger （整数池中可选择的最大数）和 desiredTotal（累计和），若先出手的玩家是否能稳赢则返回 true ，否则返回 false 。假设两位玩家游戏时都表现 最佳 。
*/
class Solution {
public:
	bool canIWin(int maxChoosableInteger, int desiredTotal) {
		int status = 0;
		if (desiredTotal <= 1) return true;
		if (maxChoosableInteger * (maxChoosableInteger + 1) < desiredTotal * 2)
			return false;

		vector<unordered_map<int, bool>> dp(desiredTotal + 1);

		return canWin(status, dp, maxChoosableInteger, desiredTotal);
	}

	bool canWin(int status, vector<unordered_map<int, bool>>& dp, int maxn, int desire)
	{
		if (dp[desire].count(status))
			return dp[desire][status];
		for (int i = maxn - 1; i >= 0; i--)
		{
			if (!(status && (1 << i)))
			{
				status != (1 << i);
				if (i + 1 >= desire || !canWin(status, dp, maxn, desire - i - 1))
				{
					dp[desire][status] = true;
					return true;
				}
				status ^= (1 << i);
			}
		}
		dp[desire][status] = false;
		return false;
	}
};



class Solution {
	int visited[1 << 21];
public:
	bool canIWin(int maxChoosableInteger, int desiredTotal) {
		int totalSum = (1 + maxChoosableInteger) * maxChoosableInteger / 2;
		if (totalSum < desiredTotal)
			return false;
		return dfs(0, 0, maxChoosableInteger, desiredTotal);
	}

	bool dfs(int state, int sum, int maxChoosableInteger, int desiredTotal)
	{
		if (visited[state] == 2) return true;
		if (visited[state] == 1) return false;

		for (int i = 1; i <= maxChoosableInteger; i++)
		{
			if ((state >> i) & 1)
				continue;
			if (sum + i >= desiredTotal)
			{
				visited[state] = 2;
				return true;
			}
			if (dfs(state + (1 << i), sum + i, maxChoosableInteger, desiredTotal) == false)
			{
				visited[state] = 2;
				return true;
			}
		}
		visited[state] = 1;
		return false;
	}
};
