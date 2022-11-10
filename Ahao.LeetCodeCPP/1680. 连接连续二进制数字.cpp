#include<vector>

using namespace std;



/*
1680. 连接连续二进制数字
给你一个整数 n ，请你将 1 到 n 的二进制表示连接起来，并返回连接结果对应的 十进制 数字对 10^9 + 7 取余的结果。
*/
class Solution {
public:
	int getLen(int x)
	{
		int res = 0;
		while (x) res++, x >>= 1;
		return res;
	}

	int concatenatedBinary(int n) {
		long long res = 0, mod = 1e9 + 7;
		for (int i = 1; i <= n; i++)
			(res = (res << getLen(i)) + i) %= mod;
		return res;
	}

	int concatenatedBinary(int n) {
		long long res = 0, mod = 1e9 + 7;
		vector<int> g(n + 1);
		for (int i = 1; i <= n; i++)
		{
			g[i] = g[i / 2] + 1;
			(res = (res << g[i]) + i) %= mod;
		}
		return res;
	}
};