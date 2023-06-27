#include<vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/*
1681. 最小不兼容性

给你一个整数数组 nums​​​ 和一个整数 k 。你需要将这个数组划分到 k 个相同大小的子集中，使得同一个子集里面没有两个相同的元素。

一个子集的 不兼容性 是该子集里面最大值和最小值的差。

请你返回将数组分成 k 个子集后，各子集 不兼容性 的 和 的 最小值 ，如果无法分成分成 k 个子集，返回 -1 。

子集的定义是数组中一些数字的集合，对数字顺序没有要求。
*/

class Solution {
public:
	int minimumIncompatibility(vector<int>& nums, int k) {
		int n = nums.size();
		vector<int> dp(1 << n, INT_MAX);
		dp[0] = 0;
		int group = n / k;
		unordered_map<int, int> values;

		for (int mask = 1; mask < (1 << n); mask++) {
			if (__builtin_popcount(mask) != group) {
				continue;
			}
			int mn = 20, mx = 0;
			unordered_set<int> cur;
			for (int i = 0; i < n; i++) {
				if (mask & (1 << i)) {
					if (cur.count(nums[i]) > 0) {
						break;
					}
					cur.insert(nums[i]);
					mn = min(mn, nums[i]);
					mx = max(mx, nums[i]);
				}
			}
			if (cur.size() == group) {
				values[mask] = mx - mn;
			}
		}

		for (int mask = 0; mask < (1 << n); mask++) {
			if (dp[mask] == INT_MAX) {
				continue;
			}
			unordered_map<int, int> seen;
			for (int i = 0; i < n; i++) {
				if ((mask & (1 << i)) == 0) {
					seen[nums[i]] = i;
				}
			}
			if (seen.size() < group) {
				continue;
			}
			int sub = 0;
			for (auto& pair : seen) {
				sub |= (1 << pair.second);
			}
			int nxt = sub;
			while (nxt > 0) {
				if (values.count(nxt) > 0) {
					dp[mask | nxt] = min(dp[mask | nxt], dp[mask] + values[nxt]);
				}
				nxt = (nxt - 1) & sub;
			}
		}

		return (dp[(1 << n) - 1] < INT_MAX) ? dp[(1 << n) - 1] : -1;
	}
};