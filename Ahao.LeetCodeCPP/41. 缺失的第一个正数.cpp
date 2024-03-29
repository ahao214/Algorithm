using namespace std;
#include<vector>

class Solution {
	/*
	41. 缺失的第一个正数
	给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。

	请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。
	*/
public:
	int firstMissingPositive(vector<int>& nums) {
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			while (nums[i] >= 1 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
				swap(nums[i], nums[nums[i] - 1]);
			}
		}
		for (int i = 0; i < n; i++) {
			if (nums[i] != i + 1) {
				return i + 1;
			}
		}
		return n + 1;
	}
};
