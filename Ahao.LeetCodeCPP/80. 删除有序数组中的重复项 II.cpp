#include<vector>

using namespace std;

class Solution {
	/*
	80. 删除有序数组中的重复项 II
	给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使每个元素 最多出现两次 ，返回删除后数组的新长度。

	不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
	*/
public:
	/*
	Times:O(n)
	Space:O(1)
	*/
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() <= 2) return nums.size();
		int idx = 1;
		for (int i = 2; i < nums.size(); i++)
		{
			if (nums[i] != nums[idx - 1])
			{
				nums[++idx] = nums[i];
			}
		}
		return idx + 1;
	}
};
