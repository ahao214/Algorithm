#include<vector>
#include <string>

using namespace std;


/*
647. 回文子串

给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。

回文字符串 是正着读和倒过来读一样的字符串。

子字符串 是字符串中的由连续字符组成的一个序列。

具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。
*/
class Solution {
public:
	int countSubstrings(string s) {
		int res = 0;
		for (int i = 0; i < s.size(); i++)
		{
			//枚举长度为奇数的情况
			for (int j = i, k = i; j >= 0 && k < s.size(); j--, k++)
			{
				if (s[j] != s[k])
					break;
				res++;
			}
			//偶数情况
			for (int j = i, k = i + 1; j >= 0 && k < s.size(); j--, k++)
			{
				if (s[j] != s[k])
					break;
				res++;
			}
		}
		return res;
	}
};
