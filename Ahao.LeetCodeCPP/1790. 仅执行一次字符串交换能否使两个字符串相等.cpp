#include<vector>
#include<string>
using namespace std;


/*
1790. 仅执行一次字符串交换能否使两个字符串相等
给你长度相等的两个字符串 s1 和 s2 。一次 字符串交换 操作的步骤如下：选出某个字符串中的两个下标（不必不同），并交换这两个下标所对应的字符。

如果对 其中一个字符串 执行 最多一次字符串交换 就可以使两个字符串相等，返回 true ；否则，返回 false 。
*/
class Solution {
public:
	bool areAlmostEqual(string s1, string s2) {
		if (s1 == s2) return true;

		for (int i = 0; i < s1.size(); i++)
		{
			for (int j = 0; j < i; j++)
			{
				swap(s1[i], s1[j]);
				if (s1 == s2)
					return true;
				swap(s1[i], s1[j]);
			}
		}
		return false;
	}
};