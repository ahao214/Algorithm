#include<vector>
#include <deque>

using namespace std;


/*
239. 滑动窗口最大值
给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

返回 滑动窗口中的最大值 。
*/
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		deque<int> dq;
		vector<int> res;
		for (int i = 0, j = 0; i < nums.size(); i++)
		{
			while (!dq.empty() && nums[dq.front()] <= nums[i])
				dq.pop_front();
			dq.push_front(i);
			if (i - j + 1 > k)
			{
				if (dq.back() <= j) dq.pop_back();
				j++;
			}
			if (i - j + 1 == k) res.push_back(nums[dq.back()]);
		}
		return res;
	}
};