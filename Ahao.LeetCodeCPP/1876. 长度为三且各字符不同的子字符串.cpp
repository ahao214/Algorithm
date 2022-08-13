#include<string>

using namespace std;


/*
1876. 长度为三且各字符不同的子字符串
如果一个字符串不含有任何重复字符，我们称这个字符串为 好 字符串。

给你一个字符串 s ，请你返回 s 中长度为 3 的 好子字符串 的数量。

注意，如果相同的好子字符串出现多次，每一次都应该被记入答案之中。

子字符串 是一个字符串中连续的字符序列。
*/
class Solution {

public:
	int countGoodSubstrings(string s) {
		int res = 0;
		for (int i = 0; i + 2 < s.size(); i++)
		{
			int a = i, b = i + 1, c = i + 2;
			if (s[a] != s[b] && s[b] != s[c] && s[a] != s[c])
				res++;
		}
		return res;
	}

};