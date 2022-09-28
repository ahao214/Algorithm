#include<vector>

using namespace std;


/*
1770. 执行乘法运算的最大分数
给你两个长度分别 n 和 m 的整数数组 nums 和 multipliers ，其中 n >= m ，数组下标 从 1 开始 计数。

初始时，你的分数为 0 。你需要执行恰好 m 步操作。在第 i 步操作（从 1 开始 计数）中，需要：

选择数组 nums 开头处或者末尾处 的整数 x 。
你获得 multipliers[i] * x 分，并累加到你的分数中。
将 x 从数组 nums 中移除。
在执行 m 步操作后，返回 最大 分数。
*/
class Solution {
public:
	int maximumScore(vector<int>& nums, vector<int>& multipliers) {
		int n = nums.size(), m = multipliers.size();
		if (n >= m * 2)
		{
			int x = m, y = n - m;
			while (y < n) nums[x++] = nums[y++];
			n = x;
		}

		vector<vector<int>> f(n + 2, vector<int>(n + 2));
		for (int len = n - m + 1; len <= n; len++)
		{
			for (int i = 1; i + len - 1 <= n; i++)
			{
				int j = i + len - 1;
				f[i][j] = max(f[i + 1][j] + nums[i - 1] * multipliers[n - len], f[i][j - 1] + nums[j - 1] * multipliers[n - len]);
			}
		}
		return f[1][n];
	}
};
