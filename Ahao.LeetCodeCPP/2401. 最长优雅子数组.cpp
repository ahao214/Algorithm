#include<vector>

using namespace std;


/*
2401. 最长优雅子数组
给你一个由 正 整数组成的数组 nums 。

如果 nums 的子数组中位于 不同 位置的每对元素按位 与（AND）运算的结果等于 0 ，则称该子数组为 优雅 子数组。
返回 最长 的优雅子数组的长度。
子数组 是数组中的一个 连续 部分。
注意：长度为 1 的子数组始终视作优雅子数组
*/
class Solution {
public:
	int longestNiceSubarray(vector<int>& nums) {
		int res = 0;
		int count = 0;
		int j = 0;
		for (int i = 0; i < nums.size(); i++) {
			while (j < nums.size() && (count & nums[j]) == 0) {
				count += nums[j];
				j++;
			}
			res = max(res, j - i);
			count -= nums[i];
		}
		return res;
	}
};