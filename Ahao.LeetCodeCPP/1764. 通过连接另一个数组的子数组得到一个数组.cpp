#include<vector>

using namespace std;



/*
1764. 通过连接另一个数组的子数组得到一个数组
给你一个长度为 n 的二维整数数组 groups ，同时给你一个整数数组 nums 。

你是否可以从 nums 中选出 n 个 不相交 的子数组，使得第 i 个子数组与 groups[i] （下标从 0 开始）完全相同，且如果 i > 0 ，那么第 (i-1) 个子数组在 nums 中出现的位置在第 i 个子数组前面。（也就是说，这些子数组在 nums 中出现的顺序需要与 groups 顺序相同）

如果你可以找出这样的 n 个子数组，请你返回 true ，否则返回 false 。

如果不存在下标为 k 的元素 nums[k] 属于不止一个子数组，就称这些子数组是 不相交 的。子数组指的是原数组中连续元素组成的一个序列。
*/
class Solution {
public:
	bool check(vector<int>& gs, vector<int>& nums, int i)
	{
		int k = 0;
		for (int j = i; k < gs.size() && j < nums.size(); k++, j++)
		{
			if (gs[k] != nums[j])
				return false;
		}
		if (k != gs.size()) return false;
		return true;
	}

	bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
		for (int i = 0, k = 0; i < nums.size(); i++)
		{
			if (check(groups[k], nums, i))
			{
				i += groups[k].size() - 1;
				k++;
				if (k == groups.size()) return true;
			}
		}
		return false;
	}
};


