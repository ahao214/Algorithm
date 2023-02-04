#include<vector>

using namespace std;



/*
922. 按奇偶排序数组 II

给定一个非负整数数组 nums，  nums 中一半整数是 奇数 ，一半整数是 偶数 。

对数组进行排序，以便当 nums[i] 为奇数时，i 也是 奇数 ；当 nums[i] 为偶数时， i 也是 偶数 。

你可以返回 任何满足上述条件的数组作为答案 。
*/
class Solution {
public:
	vector<int> sortArrayByParityII(vector<int>& nums) {
		for (int i = 0, j = 1; i < nums.size(); i += 2, j += 2)
		{
			while (i < nums.size() && nums[i] % 2 == 0) i += 2;
			while (j < nums.size() && nums[j] % 2 == 1) j += 2;
			if (i < nums.size())
				swap(nums[i], nums[j]);
		}
		return nums;
	}
};