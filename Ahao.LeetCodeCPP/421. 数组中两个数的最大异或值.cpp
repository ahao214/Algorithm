#include<vector>
#include <unordered_set>

using namespace std;


/*
421. 数组中两个数的最大异或值
给你一个整数数组 nums ，返回 nums[i] XOR nums[j] 的最大运算结果，其中 0 ≤ i ≤ j < n 。

进阶：你可以在 O(n) 的时间解决这个问题吗？
*/
class Solution {
public:
	typedef long long ll;
	int findMaximumXOR(vector<int>& nums) {
		unordered_set<ll> edge;
		int res = 0;
		for (auto& x : nums) {
			ll pre = 0, pre_op = 0;
			int xorr = 0;
			for (int i = 30; i >= 0; i--) {
				int next = x >> i & 1;
				edge.insert(pre + next * (1ll << 32) + i * (1ll << 33));
				if (edge.count(pre_op + !next * (1ll << 32) + i * (1ll << 33))) {
					xorr = xorr * 2 + 1;
					pre_op = pre_op * 2 + !next;
				}
				else {
					xorr <<= 1;
					pre_op = pre_op * 2 + next;
				}
				pre = pre * 2 + next;
			}
			res = max(res, xorr);
		}
		return res;
	}
};