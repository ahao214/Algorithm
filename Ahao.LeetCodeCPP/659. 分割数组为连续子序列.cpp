#include<vector>
#include <unordered_map>

using namespace std;

/*
659. 分割数组为连续子序列

给你一个按 非递减顺序 排列的整数数组 nums 。

请你判断是否能在将 nums 分割成 一个或多个子序列 的同时满足下述 两个 条件：

每个子序列都是一个 连续递增序列（即，每个整数 恰好 比前一个整数大 1 ）。
所有子序列的长度 至少 为 3 。
如果可以分割 nums 并满足上述条件，则返回 true ；否则，返回 false 。
*/



class Solution {
public:
	bool isPossible(vector<int>& nums) {
		unordered_map<int, int> cnt1, cnt2;
		for (auto x : nums)
			cnt1[x]++;
		for (auto x : nums)
		{
			if (!cnt1[x]) continue;
			if (cnt2[x - 1])
			{
				cnt2[x - 1]--;
				cnt2[x]++;
				cnt1[x]--;
			}
			else if (cnt1[x + 1] && cnt1[x + 2])
			{
				cnt2[x + 2]++;
				cnt1[x]--, cnt1[x + 1]--, cnt1[x + 2]--;
			}
			else
			{
				return false;
			}
		}
		return true;
	}
};
