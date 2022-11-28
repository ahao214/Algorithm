using namespace std;
#include<vector>

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() < 2) return nums.size();
		int idx = 0;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] != nums[idx]) {
				nums[++idx] = nums[i];
			}
		}
		return idx + 1;
	}
};



/*
26. 删除有序数组中的重复项
给你一个 升序排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。

由于在某些语言中不能改变数组的长度，所以必须将结果放在数组nums的第一部分。更规范地说，如果在删除重复项之后有 k 个元素，那么 nums 的前 k 个元素应该保存最终结果。

将最终结果插入 nums 的前 k 个位置后返回 k 。
*/
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() < 2) return nums.size();
		int idx = 0;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] != nums[idx]) {
				nums[++idx] = nums[i];
			}
		}
		return idx + 1;
	}
};



