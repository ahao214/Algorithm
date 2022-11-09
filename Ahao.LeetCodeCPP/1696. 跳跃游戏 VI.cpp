#include<vector>
#include <deque>

using namespace std;


/*
1696. 跳跃游戏 VI
给你一个下标从 0 开始的整数数组 nums 和一个整数 k 。

一开始你在下标 0 处。每一步，你最多可以往前跳 k 步，但你不能跳出数组的边界。也就是说，你可以从下标 i 跳到 [i + 1， min(n - 1, i + k)] 包含 两个端点的任意位置。

你的目标是到达数组最后一个位置（下标为 n - 1 ），你的 得分 为经过的所有数字之和。

请你返回你能得到的 最大得分 。
*/
class Solution {
public:
	int maxResult(vector<int>& nums, int k) {
		int n = nums.size();
		vector<int> f(n);
		f[0] = nums[0];
		deque<int> q;
		q.push_back(0);
		for (int i = 1; i < n; i++)
		{
			while (q.front() < i - k) q.pop_front();
			f[i] = f[q.front()] + nums[i];
			while (q.size() && f[q.back()] <= f[i])
				q.pop_back();
			q.push_back(i);
		}
		return f[n - 1];
	}
};
