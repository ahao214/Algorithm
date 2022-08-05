#include<vector>

using namespace std;

/*
1925. 统计平方和三元组的数目
一个 平方和三元组 (a,b,c) 指的是满足 a^2 + b^2 = c^2 的 整数 三元组 a，b 和 c 。

给你一个整数 n ，请你返回满足 1 <= a, b, c <= n 的 平方和三元组 的数目。
*/
class Solution {
public:
	int countTriples(int n) {
		int res = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				for (int k = 1; k <= n; k++)
					if (i * i + j * j == k * k)
						res++;
		return res;
	}
};

