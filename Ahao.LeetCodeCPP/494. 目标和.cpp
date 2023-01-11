#include<vector>

using namespace std;



/*
494. 目标和

给你一个整数数组 nums 和一个整数 target 。

向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：

例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。
*/
class Solution {
	int dp[25][2005];
public:
	int findTargetSumWays(vector<int>& nums, int target) {
		int n = nums.size();
		nums.insert(nums.begin(), 0);
		int offset = 1000;
		dp[0][0 + offset] = 1;

		for (int i = 1; i <= n; i++) {
			for (int s = -1000; s <= 1000; s++) {
				if (s - nums[i] >= -1000 && s - nums[i] <= 1000)
					dp[i][s + offset] += dp[i - 1][s - nums[i] + offset];
				if (s + nums[i] >= -1000 && s + nums[i] <= 1000)
					dp[i][s + offset] += dp[i - 1][s + nums[i] + offset];
			}
		}
		return dp[n][target + offset];
	}
};