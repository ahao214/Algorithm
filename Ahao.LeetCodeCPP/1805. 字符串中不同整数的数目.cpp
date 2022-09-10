#include<vector>
#include<string>
#include<unordered_set>

using namespace std;


/*
1805. 字符串中不同整数的数目
给你一个字符串 word ，该字符串由数字和小写英文字母组成。

请你用空格替换每个不是数字的字符。例如，"a123bc34d8ef34" 将会变成 " 123  34 8  34" 。注意，剩下的这些整数为（相邻彼此至少有一个空格隔开）："123"、"34"、"8" 和 "34" 。

返回对 word 完成替换后形成的 不同 整数的数目。

只有当两个整数的 不含前导零 的十进制表示不同， 才认为这两个整数也不同。
*/
class Solution {
public:
	int numDifferentIntegers(string word) {
		unordered_set<string> nums;
		for (int i = 0; i < word.size(); i++)
		{
			if (!isdigit(word[i])) continue;
			string s;
			int j = i;
			while (j < word.size() && isdigit(word[j]))
				s += word[j++];
			int k = 0;
			while (k + 1 < s.size() && s[k] == '0') k++;
			nums.insert(s.substr(k));
			i = j;
		}
		return nums.size();
	}
};