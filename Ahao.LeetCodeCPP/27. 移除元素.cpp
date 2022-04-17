using namespace std;
#include<vector>;


class Solution {
	/*
	27. 移除元素
	给你一个数组 nums 和一个值 val，你需要原地移除所有数值等于val的元素，并返回移除后数组的新长度。
	不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并原地修改输入数组。
	元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
	*/
public:
	int removeElement(vector<int>& nums, int val) {
		int idx = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] != val) {
				nums[idx++] = nums[i];
			}
		}
		return idx;
	}
};
