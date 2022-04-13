#include <climits>
using namespace std;



class Solution {
/*
7. 整数反转
给你一个32位的有符号整数x,返回将x中的数字部分反转后的结果。
如果反转后整数超过 32 位的有符号整数的范围 [−2^31,2^31 − 1],就返回 0。

假设环境不允许存储 64 位整数（有符号或无符号）。
*/

public:
	int reverse(int x) {
		int res = 0;
		while (x) {
			if (x > 0 && res > (INT_MAX - x % 10) / 10)
				return 0;
			if (x < 0 && res < (INT_MIN - x % 10) / 10)
				return 0;
			res = res * 10 + x % 10;
			x /= 10;
		}
		return res;
	}
};