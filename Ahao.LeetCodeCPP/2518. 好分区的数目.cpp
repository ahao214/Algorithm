#include<vector>
#include <numeric>

using namespace std;




/*
2518. 好分区的数目
给你一个正整数数组 nums 和一个整数 k 。

分区 的定义是：将数组划分成两个有序的 组 ，并满足每个元素 恰好 存在于 某一个 组中。如果分区中每个组的元素和都大于等于 k ，则认为分区是一个好分区。

返回 不同 的好分区的数目。由于答案可能很大，请返回对 109 + 7 取余 后的结果。

如果在两个分区中，存在某个元素 nums[i] 被分在不同的组中，则认为这两个分区不同。
*/
using LL = long long;
LL MOD = 1e9 + 7;
class Solution {
	LL dp[1005][1005];
public:
	int countPartitions(vector<int>& nums, int k) {
		if (accumulate(nums.begin(), nums.end(), 0LL) < 2 * k)
			return 0;

		int n = nums.size();
		nums.insert(nums.begin(), 0);

		dp[0][0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int s = 0; s < k; s++) {
				dp[i][s] += dp[i - 1][s];
				if (s >= nums[i]) {
					dp[i][s] += dp[i - 1][s - nums[i]];
				}
				dp[i][s] %= MOD;
			}
		}

		LL invalid = 0;
		for (int s = 0; s < k; s++) {
			invalid = (invalid + dp[n][s]) % MOD;
		}

		int total = 1;
		for (int i = 0; i < n; i++) {
			total = (total * 2) % MOD;
		}
		return (total - 2 * invalid + MOD) % MOD;
	}
};

