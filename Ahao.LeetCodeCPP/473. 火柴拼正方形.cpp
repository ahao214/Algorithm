using namespace std;

#include<vector>
#include <numeric>
#include <algorithm>

//回溯
class Solution {
public:
	bool dfs(int index, vector<int>& matchsticks, vector<int>& edges, int len) {
		if (index == matchsticks.size()) {
			return true;
		}
		for (int i = 0; i < edges.size(); i++) {
			edges[i] += matchsticks[index];
			if (edges[i] <= len && dfs(index + 1, matchsticks, edges, len)) {
				return true;
			}
			edges[i] -= matchsticks[index];
		}
		return false;
	}

	bool makesquare(vector<int>& matchsticks) {
		int totalLen = accumulate(matchsticks.begin(), matchsticks.end(), 0);
		if (totalLen % 4 != 0) {
			return false;
		}
		sort(matchsticks.begin(), matchsticks.end(), greater<int>()); // 减少搜索量

		vector<int> edges(4);
		return dfs(0, matchsticks, edges, totalLen / 4);
	}
};



//方法二：状态压缩 + 动态规划
class Solution {
public:
	bool makesquare(vector<int>& matchsticks) {
		int totalLen = accumulate(matchsticks.begin(), matchsticks.end(), 0);
		if (totalLen % 4 != 0) {
			return false;
		}
		int len = totalLen / 4, n = matchsticks.size();
		vector<int> dp(1 << n, -1);
		dp[0] = 0;
		for (int s = 1; s < (1 << n); s++) {
			for (int k = 0; k < n; k++) {
				if ((s & (1 << k)) == 0) {
					continue;
				}
				int s1 = s & ~(1 << k);
				if (dp[s1] >= 0 && dp[s1] + matchsticks[k] <= len) {
					dp[s] = (dp[s1] + matchsticks[k]) % len;
					break;
				}
			}
		}
		return dp[(1 << n) - 1] == 0;
	}
};


/*
473. 火柴拼正方形
你将得到一个整数数组 matchsticks ，其中 matchsticks[i] 是第 i 个火柴棒的长度。你要用 所有的火柴棍 拼成一个正方形。你 不能折断 任何一根火柴棒，但你可以把它们连在一起，而且每根火柴棒必须 使用一次 。

如果你能使这个正方形，则返回 true ，否则返回 false
*/
class Solution {
public:
	vector<bool> st;

	bool makesquare(vector<int>& matchsticks) {
		int sum = 0;
		for (auto u : matchsticks) sum += u;
		if (!sum || sum % 4) return false;

		sort(matchsticks.begin(), matchsticks.end());
		reverse(matchsticks.begin(), matchsticks.end());

		st = vector<bool>(matchsticks.size());
		return dfs(matchsticks, 0, 0, sum / 4);
	}

	bool dfs(vector<int>& nums, int u, int cur, int length)
	{
		if (cur == length) u++, cur = 0;
		if (u == 4) return true;
		for (int i = 0; i < nums.size(); i++)
		{
			if (!st[i] && cur + nums[i] <= length)
			{
				st[i] = true;
				if (dfs(nums, u, cur + nums[i], length)) return true;
				st[i] = false;
				if (!cur) return false;
				if (cur + nums[i] == length) return false;
				while (i + 1 < nums.size() && nums[i + 1] == nums[i]) i++;
			}
		}
		return false;
	}
};
