#include<vector>

using namespace std;


/*
2006. 差的绝对值为 K 的数对数目
给你一个整数数组 nums 和一个整数 k ，请你返回数对 (i, j) 的数目，满足 i < j 且 |nums[i] - nums[j]| == k 。

|x| 的值定义为：

如果 x >= 0 ，那么值为 x 。
如果 x < 0 ，那么值为 -x 。
*/
class Solution {
public:
	int countKDifference(vector<int>& nums, int k) {
		int n = nums.size(), res = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if (abs(nums[i] - nums[j]) == k)
					res++;
			}
		}
		return res;
	}
};