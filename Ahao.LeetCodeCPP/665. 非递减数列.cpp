#include<vector>

using namespace std;


/*
665. 非递减数列

给你一个长度为 n 的整数数组 nums ，请你判断在 最多 改变 1 个元素的情况下，该数组能否变成一个非递减数列。

我们是这样定义一个非递减数列的： 对于数组中任意的 i (0 <= i <= n-2)，总满足 nums[i] <= nums[i + 1]。
*/
class Solution {
public:
	bool check(vector<int>& nums)
	{
		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] < nums[i - 1])
				return false;
		}
		return true;
	}

	bool checkPossibility(vector<int>& nums) {
		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] < nums[i - 1])
			{
				int a = nums[i - 1], b = nums[i];
				nums[i - 1] = nums[i] = a;
				if (check(nums)) return true;
				nums[i - 1] = nums[i] = b;
				if (check(nums)) return true;
				return false;
			}
		}
		return true;
	}
};
