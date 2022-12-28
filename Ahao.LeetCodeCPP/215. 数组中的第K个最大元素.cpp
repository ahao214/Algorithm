#include<vector>

using namespace std;



/*
215. 数组中的第K个最大元素
给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。

请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
*/
class Solution {
	int partition(vector<int>& nums, int left, int right)
	{
		int pivot = nums[right], p = left;
		for (int i = left; i < right; i++)
		{
			if (nums[i] < pivot)
			{
				swap(nums[i], nums[p]);
				p++;
			}
		}
		swap(nums[p], nums[right]);
		return p;
	}

	void helper(vector<int>& nums, int left, int right, int k)
	{
		if (left >= right)
		{
			return;
		}
		int position = partition(nums, left, right);
		if (position == nums.size() - k)
			return;
		if (position < nums.size() - k)
			helper(nums, position + 1, right, k);
		else
			helper(nums, left, position - 1, k);
	}

public:
	int findKthLargest(vector<int>& nums, int k) {
		helper(nums, 0, nums.size() - 1, k);
		return nums[nums.size() - k];
	}
};