#include<string>

using namespace std;



/*
1758. 生成交替二进制字符串的最少操作数
给你一个仅由字符 '0' 和 '1' 组成的字符串 s 。一步操作中，你可以将任一 '0' 变成 '1' ，或者将 '1' 变成 '0' 。

交替字符串 定义为：如果字符串中不存在相邻两个字符相等的情况，那么该字符串就是交替字符串。例如，字符串 "010" 是交替字符串，而字符串 "0100" 不是。

返回使 s 变成 交替字符串 所需的 最少 操作数。
*/
class Solution {
public:
	int work(char c, string s)
	{
		int res = 0;
		for (auto x : s)
		{
			if (c == x) res++;
			c ^= 1;
		}
		return res;
	}

	int minOperations(string s) {
		return min(work('0', s), work('1', s));
	}
};

class Solution {
public:
	int minOperations(string s) {
		int cnt = 0;
		for (int i = 0; i < s.size(); i++) {
			char c = s[i];
			if (c != ('0' + i % 2)) {
				cnt++;
			}
		}
		return min(cnt, (int)s.size() - cnt);
	}
};
