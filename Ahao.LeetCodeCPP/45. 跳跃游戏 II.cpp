using namespace std;
#include<vector>


class Solution {
	/*
	45. 跳跃游戏 II
	给你一个非负整数数组 nums ，你最初位于数组的第一个位置。

	数组中的每个元素代表你在该位置可以跳跃的最大长度。

	你的目标是使用最少的跳跃次数到达数组的最后一个位置。

	假设你总是可以到达数组的最后一个位置。
	*/
public:
	int jump(vector<int>& nums) {
		int maxPos = 0, end = 0;
		int res = 0;
		for (int i = 0; i < nums.size() - 1; i++)
		{
			maxPos = max(maxPos, nums[i] + i);
			if (i == end)
			{
				end = maxPos;
				res++;
			}
		}
		return res;
	}
};

