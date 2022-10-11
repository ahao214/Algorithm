#include<string>

using namespace std;



/*
1750. 删除字符串两端相同字符后的最短长度
给你一个只包含字符 'a'，'b' 和 'c' 的字符串 s ，你可以执行下面这个操作（5 个步骤）任意次：

选择字符串 s 一个 非空的前缀，这个前缀的所有字符都相同。
选择字符串 s 一个 非空的后缀，这个后缀的所有字符都相同。
前缀和后缀在字符串中任意位置都不能有交集。
前缀和后缀包含的所有字符都要相同。
同时删除前缀和后缀。
请你返回对字符串 s 执行上面操作任意次以后（可能 0 次），能得到的 最短长度 。
*/
class Solution {
public:
	int minimumLength(string s) {
		int i = 0, j = s.size() - 1;
		while (i < j)
		{
			if (s[i] != s[j])
				break;
			char c = s[i];
			while (i <= j && s[i] == c) i++;
			while (i <= j && s[j] == c) j--;
		}
		return j - i + 1;
	}
};