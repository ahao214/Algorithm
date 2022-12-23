#include<vector>

using namespace std;


/*
263. 丑数
给你一个整数 n ，请你判断 n 是否为 丑数 。如果是，返回 true ；否则，返回 false 。

丑数 就是只包含质因数 2、3 和/或 5 的正整数。
*/
class Solution {
public:
	bool isUgly(int n) {
		int d[] = { 2,3,5 };
		for (auto prime : d)
		{
			while (n > 0 && n % prime == 0)
				n /= prime;
		}
		return n == 1;
	}
};