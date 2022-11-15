#include<vector>

using namespace std;


/*
1493. 删掉一个元素以后全为 1 的最长子数组
给你一个二进制数组 nums ，你需要从中删掉一个元素。

请你在删掉元素的结果数组中，返回最长的且只包含 1 的非空子数组的长度。

如果不存在这样的子数组，请返回 0 。
*/
class Solution {
public:
	//使用双指针i和j，是区间i和j之间始终保持只有一个0
	//每个区间的长度是i-j,在求每个区间值的最大值
	int longestSubarray(vector<int>& nums) {
		int res = 0;
		//zero表示0的个数
		for (int i = 0, j = 0, zero = 0; i < nums.size(); i++)
		{
			if (nums[i] == 0) zero++;
			while (zero > 1)
				zero -= !nums[j++];
			res = max(res, i - j);
		}
		return res;
	}
};