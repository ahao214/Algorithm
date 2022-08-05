#include<vector>

using namespace std;


/*
1909. 删除一个元素使数组严格递增
给你一个下标从 0 开始的整数数组 nums ，如果 恰好 删除 一个 元素后，数组 严格递增 ，那么请你返回 true ，否则返回 false 。如果数组本身已经是严格递增的，请你也返回 true 。

数组 nums 是 严格递增 的定义为：对于任意下标的 1 <= i < nums.length 都满足 nums[i - 1] < nums[i] 。
*/
class Solution {
public:
	bool canBeIncreasing(vector<int>& nums) {
		for (int i = -1; i < (int)nums.size(); i++)
		{
			bool flag = false;
			int last = 0;
			for (int j = 0; j < nums.size(); j++)
			{
				if (j == i) continue;
				if (nums[j] <= last) flag = true;
				last = nums[j];
			}
			if (!flag) return true;
		}
		return false;
	}
};