#include<vector>

using namespace std;


/*
1799. N 次操作后的最大分数和
给你 nums ，它是一个大小为 2 * n 的正整数数组。你必须对这个数组执行 n 次操作。

在第 i 次操作时（操作编号从 1 开始），你需要：

选择两个元素 x 和 y 。
获得分数 i * gcd(x, y) 。
将 x 和 y 从 nums 中删除。
请你返回 n 次操作后你能获得的分数和最大为多少。

函数 gcd(x, y) 是 x 和 y 的最大公约数。
*/
class Solution {
public:
	int gcd(int a, int b)
	{
		return b ? gcd(b, a % b) : a;
	}
	int maxScore(vector<int>& nums) {
		int n = nums.size();
		vector<int> f(1 << n);
		for (int i = 0; i < 1 << n; i++)
		{
			int cnt = 0;
			for (int j = 0; j < n; j++)
			{
				if (!(i >> j & 1))
					cnt++;
			}
			cnt = cnt / 2 + 1;
			for (int j = 0; j < n; j++)
			{
				if (i >> j & 1)
					for (int k = j + 1; k < n; k++)
						if (i >> k & 1)
							f[i] = max(f[i], f[i - (1 << j) - (1 << k)] + gcd(nums[j], nums[k]) * cnt);
			}
		}
		return f[(1 << n) - 1];
	}
};


class Solution {
public:
    int maxScore(vector<int>& nums) {
        int m = nums.size();
        vector<int> dp(1 << m, 0);
        vector<vector<int>> gcd_tmp(m, vector<int>(m, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = i + 1; j < m; ++j) {
                gcd_tmp[i][j] = gcd(nums[i], nums[j]);
            }
        }
        int all = 1 << m;
        for (int s = 1; s < all; ++s) {
            int t = __builtin_popcount(s);
            if (t & 1) {
                continue;
            }
            for (int i = 0; i < m; ++i) {
                if ((s >> i) & 1) {
                    for (int j = i + 1; j < m; ++j) {
                        if ((s >> j) & 1) {
                            dp[s] = max(dp[s], dp[s ^ (1 << i) ^ (1 << j)] + t / 2 * gcd_tmp[i][j]);
                        }
                    }
                }
            }
        }
        return dp[all - 1];
    }
};
