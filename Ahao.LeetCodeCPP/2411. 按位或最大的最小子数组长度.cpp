#include<vector>

using namespace std;



/*
2411. 按位或最大的最小子数组长度
给你一个长度为 n 下标从 0 开始的数组 nums ，数组中所有数字均为非负整数。对于 0 到 n - 1 之间的每一个下标 i ，你需要找出 nums 中一个 最小 非空子数组，它的起始位置为 i （包含这个位置），同时有 最大 的 按位或运算值 。

换言之，令 Bij 表示子数组 nums[i...j] 的按位或运算的结果，你需要找到一个起始位置为 i 的最小子数组，这个子数组的按位或运算的结果等于 max(Bik) ，其中 i <= k <= n - 1 。
一个数组的按位或运算值是这个数组里所有数字按位或运算的结果。

请你返回一个大小为 n 的整数数组 answer，其中 answer[i]是开始位置为 i ，按位或运算结果最大，且 最短 子数组的长度。

子数组 是数组里一段连续非空元素组成的序列。
*/
class Solution {
public:
	vector<int> smallestSubarrays(vector<int>& nums) {
		int n = nums.size();
		int j = n - 1;

		vector<int> count(32, 0);
		vector<int>res(n);
		for (int i = n - 1; i >= 0; i--) {
			for (int k = 0; k < 32; k++) {
				count[k] += ((nums[i] >> k) & 1);
			}
			while (j > i && ok2remove(nums[j], count)) {
				for (int k = 0; k < 32; k++) {
					count[k] -= ((nums[j] >> k) & 1);
				}
				j--;
			}
			res[i] = j - i + 1;
		}
		return res;
	}

	bool ok2remove(int num, vector<int>& count) {
		for (int k = 0; k < 32; k++) {
			if (count[k] == 1 && ((num >> k) & 1))
				return false;
		}
		return true;
	}
};

