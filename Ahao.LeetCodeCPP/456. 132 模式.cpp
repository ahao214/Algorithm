#include<vector>
#include <stack>

using namespace std;


/*
456. 132 模式
给你一个整数数组 nums ，数组中共有 n 个整数。132 模式的子序列 由三个整数 nums[i]、nums[j] 和 nums[k] 组成，并同时满足：i < j < k 和 nums[i] < nums[k] < nums[j] 。

如果 nums 中存在 132 模式的子序列 ，返回 true ；否则，返回 false 。
*/
class Solution {
public:
	bool find132pattern(vector<int>& nums) {
		int s = INT_MIN;
		stack<int> stk;
		for (int i = nums.size() - 1; i >= 0; i--)
		{
			if (nums[i] < s) return true;
			while (stk.size() && stk.top() <= nums[i])
			{
				s = max(s, stk.top());
				stk.pop();
			}
			stk.push(nums[i]);
		}
		return false;
	}
};