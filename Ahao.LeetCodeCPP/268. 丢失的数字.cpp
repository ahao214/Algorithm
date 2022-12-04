#include<vector>

using namespace std;


/*
268. 丢失的数字
给定一个包含 [0, n] 中 n 个数的数组 nums ，找出 [0, n] 这个范围内没有出现在数组中的那个数。
*/
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int sum = 0;
		for (auto x : nums) sum += x;
		return nums.size() * (nums.size() + 1) / 2 - sum;
	}
};