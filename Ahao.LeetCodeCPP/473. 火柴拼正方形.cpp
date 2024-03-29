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



/*
473. 火柴拼正方形
*/
class Solution {
public:
	bool makesquare(vector<int>& matchsticks) {
		if (matchsticks.size() < 4) return false; // 边数小于4
		int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
		if (sum % 4) return false; // 和不是4的倍数
		sort(matchsticks.begin(), matchsticks.end(), greater<int>());
		// 从大到小排序，优先选用大的边可以令不成功的情况更快返回
		vector<int> bucket(4); // 定义4个边的值
		return dfs(0, matchsticks, sum / 4, bucket);
	}

	bool dfs(int index, vector<int>& matchsticks, int target, vector<int>& bucket) {
		//index为当前遍历到的下标，matchsticks为边长数组，target为目标边长，bucket表示当前每条边的长度
		if (index >= matchsticks.size()) // 每条边都用了
			return (bucket[0] == bucket[1]) && (bucket[1] == target) && (bucket[2] == target);
		for (int i = 0; i < 4; i++) { // 将当前的边放在4个桶中分别尝试
			if (bucket[i] + matchsticks[index] > target) continue; // 说明不可以放在这个边上
			bucket[i] += matchsticks[index]; // 否则放入该边后继续dfs
			if (dfs(index + 1, matchsticks, target, bucket)) return true;
			bucket[i] -= matchsticks[index]; // 注意回溯的恢复状态
		}
		return false;
	}
};
