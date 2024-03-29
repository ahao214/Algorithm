#include<vector>
#include <numeric>

using namespace std;


/*
416. 分割等和子集
给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
*/
class Solution {
	int dp[205][20005];
public:
	bool canPartition(vector<int>& nums) {
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if (sum % 2 == 1)
			return false;

		int n = nums.size();
		nums.insert(nums.begin(), 0);

		dp[0][0] = true;
		for (int i = 1; i <= n; i++) {
			for (int s = 0; s <= sum / 2; s++) {
				dp[i][s] = dp[i - 1][s] || (s >= nums[i] && dp[i - 1][s - nums[i]]);
			}
		}

		return dp[n][sum / 2];
	}
};