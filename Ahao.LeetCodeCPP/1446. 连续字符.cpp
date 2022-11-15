#include<vector>
#include <string>

using namespace std;


/*
1446. 连续字符
给你一个字符串 s ，字符串的「能量」定义为：只包含一种字符的最长非空子字符串的长度。

请你返回字符串的能量。
*/
class Solution {
public:
	//双指针
	int maxPower(string s) {
		int res = 0;
		for (int i = 0; i < s.size();)
		{
			int j = i + 1;
			while (j < s.size() && s[j] == s[i]) j++;
			res = max(res, j - i);
			i = j;
		}
		return res;
	}
};