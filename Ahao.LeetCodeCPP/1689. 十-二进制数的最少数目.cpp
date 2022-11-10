#include<vector>
#include<string>

using namespace std;


/*
1689. 十-二进制数的最少数目
如果一个十进制数字不含任何前导零，且每一位上的数字不是 0 就是 1 ，那么该数字就是一个 十-二进制数 。例如，101 和 1100 都是 十-二进制数，而 112 和 3001 不是。

给你一个表示十进制整数的字符串 n ，返回和为 n 的 十-二进制数 的最少数目。
*/
class Solution {
public:
	int minPartitions(string n) {
		int res = 0;
		for (auto c : n) res = max(res, c - '0');
		return res;
	}
};
