#include<vector>
#include<string>

using namespace std;


/*
1869. 哪种连续子字符串更长
给你一个二进制字符串 s 。如果字符串中由 1 组成的 最长 连续子字符串 严格长于 由 0 组成的 最长 连续子字符串，返回 true ；否则，返回 false 。

例如，s = "110100010" 中，由 1 组成的最长连续子字符串的长度是 2 ，由 0 组成的最长连续子字符串的长度是 3 。
注意，如果字符串中不存在 0 ，此时认为由 0 组成的最长连续子字符串的长度是 0 。字符串中不存在 1 的情况也适用此规则。
*/
class Solution {
public:
	bool checkZeroOnes(string s) {
		int one = 0, zero = 0;
		int s1 = 0, s0 = 0;
		for (auto c : s)
		{
			if (c == '0') s0++, s1 = 0;
			else s1++, s0 = 0;
			one = max(one, s1), zero = max(zero, s0);
		}
		return one > zero;
	}
};