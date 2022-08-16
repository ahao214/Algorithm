#include<vector>

using namespace std;


/*
1866. 恰有 K 根木棍可以看到的排列数目
有 n 根长度互不相同的木棍，长度为从 1 到 n 的整数。请你将这些木棍排成一排，并满足从左侧 可以看到 恰好 k 根木棍。从左侧 可以看到 木棍的前提是这个木棍的 左侧 不存在比它 更长的 木棍。

例如，如果木棍排列为 [1,3,2,5,4] ，那么从左侧可以看到的就是长度分别为 1、3 、5 的木棍。
给你 n 和 k ，返回符合题目要求的排列 数目 。由于答案可能很大，请返回对 109 + 7 取余 的结果。
*/
typedef long long LL;
const int N = 1010, MOD = 1e9 + 7;
int f[N][N];
class Solution {
public:
	int rearrangeSticks(int n, int k) {
		f[0][0] = 1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= k; j++)
			{
				f[i][j] = (f[i - 1][j - 1] + (LL)(i - 1) * (f[i - 1][j])) % MOD;
			}
		}
		return f[n][k];
	}
};


