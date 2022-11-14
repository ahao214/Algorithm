#include<vector>
#include <algorithm>

using namespace std;


/*
1509. 三次操作后最大值与最小值的最小差
给你一个数组 nums ，每次操作你可以选择 nums 中的任意一个元素并将它改成任意值。

请你返回三次操作后， nums 中最大值与最小值的差的最小值。
*/
class Solution {
public:
	int minDifference(vector<int>& nums) {
		if (nums.size() <= 3) return 0;

		sort(nums.begin(), nums.end());
		int res = INT_MAX;
		for (int i = 0, j = 3; i <= 3; i++, j--)
		{
			res = min(res, nums[nums.size() - 1 - j] - nums[i]);
		}
		return res;
	}
};