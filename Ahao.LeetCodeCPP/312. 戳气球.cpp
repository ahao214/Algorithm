#include<vector>

using namespace std;



/*
312. 戳气球

有 n 个气球，编号为0 到 n - 1，每个气球上都标有一个数字，这些数字存在数组 nums 中。

现在要求你戳破所有的气球。戳破第 i 个气球，你可以获得 nums[i - 1] * nums[i] * nums[i + 1] 枚硬币。 这里的 i - 1 和 i + 1 代表和 i 相邻的两个气球的序号。如果 i - 1或 i + 1 超出了数组的边界，那么就当它是一个数字为 1 的气球。

求所能获得硬币的最大数量。
*/
class Solution {
public:
	int maxCoins(vector<int>& nums) {
		int n = nums.size();
		vector<int> a(n + 2, 1);
		for (int i = 1; i <= n; i++) a[i] = nums[i - 1];
		vector<vector<int>>f(n + 2, vector<int>(n + 2));
		for (int len = 3; len <= n + 2; len++)
		{
			for (int i = 0; i + len - 1 <= n + 1; i++)
			{
				int j = i + len - 1;
				for (int k = i + 1; k < j; k++)
					f[i][j] = max(f[i][j], f[i][k] + f[k][j] + a[i] * a[k] * a[j]);
			}
		}

		return f[0][n + 1];
	}
};