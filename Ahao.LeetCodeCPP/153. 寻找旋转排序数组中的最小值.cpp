#include<vector>

using namespace std;



/*
153. 寻找旋转排序数组中的最小值

已知一个长度为 n 的数组，预先按照升序排列，经由 1 到 n 次 旋转 后，得到输入数组。例如，原数组 nums = [0,1,2,4,5,6,7] 在变化后可能得到：
若旋转 4 次，则可以得到 [4,5,6,7,0,1,2]
若旋转 7 次，则可以得到 [0,1,2,4,5,6,7]
注意，数组 [a[0], a[1], a[2], ..., a[n-1]]旋转一次的结果为数组 [a[n-1], a[0], a[1], a[2], ..., a[n-2]] 。

给你一个元素值互不相同的数组nums ，它原来是一个升序排列的数组，并按上述情形进行了多次旋转。请你找出并返回数组中的最小元素 。
*/
class Solution {
public:
	int findMin(vector<int>& nums) {
		if (nums[0] < nums.back()) return nums[0];
		int l = 0, r = nums.size() - 1;
		while (l < r)
		{
			int mid = (l + r) >> 1;
			if (nums[mid] >= nums[0])
				l = mid + 1;
			else
				r = mid;
		}
		return nums[r];
	}
};



class Solution {
public:
	int findMin(vector<int>& nums) {
		if (nums[0] < nums.back()) return nums[0];
		int l = 0, r = nums.size() - 1;
		while (l < r)
		{
			int mid = (l + r) >> 1;
			if (nums[mid] >= nums[0])
				l = mid + 1;
			else
				r = mid;
		}
		return nums[r];
	}
};




class Solution {
public:
	int findMin(vector<int>& nums) {
		int left = 0, right = nums.size() - 1;
		while (left < right)
		{
			int mid = left + (right - left) / 2;
			if (nums[mid] <= nums.back())
				right = mid;
			else
				left = mid + 1;
		}
		return nums[right];
	}
};