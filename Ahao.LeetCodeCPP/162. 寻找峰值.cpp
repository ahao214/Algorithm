#include<vector>

using namespace std;


/*
162. 寻找峰值

峰值元素是指其值严格大于左右相邻值的元素。

给你一个整数数组 nums，找到峰值元素并返回其索引。数组可能包含多个峰值，在这种情况下，返回 任何一个峰值 所在位置即可。

你可以假设 nums[-1] = nums[n] = -∞ 。

你必须实现时间复杂度为 O(log n) 的算法来解决此问题。
*/
class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		if (nums.size() == 1 || nums[0] > nums[1])
			return 0;
		int left = 1, right = nums.size() - 1;
		while (left < right)
		{
			int mid = (left + right + 1) >> 1;
			if (nums[mid] > nums[mid - 1])
			{
				left = mid;
			}
			else
			{
				right = mid - 1;
			}
		}
		return right;
	}
};




class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int left = 0, right = nums.size() - 1;
		while (left < right)
		{
			int mid = left + right >> 1;
			if (nums[mid] > nums[mid + 1])
				right = mid;
			else
				left = mid + 1;
		}
		return right;
	}
};




class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int left = 0, right = nums.size() - 1;
		while (left < right)
		{
			int mid = left + (right - left) / 2;
			if (nums[mid] > nums[mid + 1])
				right = mid;
			else
				left = mid + 1;
		}
		return right;
	}
};