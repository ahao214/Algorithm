#include<vector>

using namespace std;


/*
343. 整数拆分
给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。

返回 你可以获得的最大乘积 。
*/
class Solution {
public:
	int integerBreak(int n) {
		if (n <= 3) return n - 1;
		int res = 1;
		if (n % 3 == 1) res *= 4, n -= 4;
		else if (n % 3 == 2) res *= 2, n -= 2;
		while (n > 0) res *= 3, n -= 3;
		return res;
	}
};
