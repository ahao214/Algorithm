#include<vector>

using namespace std;



/*
1994. 好子集的数目
给你一个整数数组 nums 。如果 nums 的一个子集中，所有元素的乘积可以表示为一个或多个 互不相同的质数 的乘积，那么我们称它为 好子集 。

比方说，如果 nums = [1, 2, 3, 4] ：
[2, 3] ，[1, 2, 3] 和 [1, 3] 是 好 子集，乘积分别为 6 = 2*3 ，6 = 2*3 和 3 = 3 。
[1, 4] 和 [4] 不是 好 子集，因为乘积分别为 4 = 2*2 和 4 = 2*2 。
请你返回 nums 中不同的 好 子集的数目对 109 + 7 取余 的结果。

nums 中的 子集 是通过删除 nums 中一些（可能一个都不删除，也可能全部都删除）元素后剩余元素组成的数组。如果两个子集删除的下标不同，那么它们被视为不同的子集。
*/
typedef long long LL;
const int MOD = 1e9 + 7;
class Solution {
public:
	int s[31] = { 0 };
	int g[31][31] = { 0 };
	int st[31] = { 0 };
	vector<int> path;
	int c = 1;

	int gcd(int a, int b)
	{
		return b ? gcd(b, a % b) : a;
	}

	int dfs(int u, int sum)
	{
		if (!sum) return 0;
		if (u > 30)
		{
			if (path.empty()) return 0;
			return sum * (LL)c % MOD;
		}
		int res = dfs(u + 1, sum);
		if (!st[u])
		{
			bool flag = true;
			for (auto x : path)
			{
				if (g[x][u])
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				path.push_back(u);
				res = (res + dfs(u + 1, sum * (LL)s[u] % MOD)) % MOD;
				path.pop_back();
			}
		}
		return res;
	}

	int numberOfGoodSubsets(vector<int>& nums) {
		for (auto x : nums)
			s[x]++;
		for (int i = 0; i < s[1]; i++)
			c = c * 2 % MOD;

		for (int i = 2; i * i <= 30; i++)
		{
			for (int j = 1; j * i * i <= 30; j++)
				st[j * i * i] = 1;
		}

		for (int i = 1; i <= 30; i++)
			for (int j = 1; j <= 30; j++)
				if (gcd(i, j) > 1)
					g[i][j] = 1;

		return dfs(2, 1);
	}
};

