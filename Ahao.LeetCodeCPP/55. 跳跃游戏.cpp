using namespace std;

#include<vector>


class Solution {
	/*
	55. 跳跃游戏
	给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。

	数组中的每个元素代表你在该位置可以跳跃的最大长度。

	判断你是否能够到达最后一个下标。
	*/
public:
	bool canJump(vector<int>& nums) {
		for (int i = 0, maxPos = 0; i < nums.size(); i++)
		{
			if (i > maxPos) return false;
			maxPos = max(maxPos, i + nums[i]);
		}
		return true;
	}
};