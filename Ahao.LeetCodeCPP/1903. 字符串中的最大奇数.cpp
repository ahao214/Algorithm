#include<vector>
#include<string>

using namespace std;


/*
1903. 字符串中的最大奇数
给你一个字符串 num ，表示一个大整数。请你在字符串 num 的所有 非空子字符串 中找出 值最大的奇数 ，并以字符串形式返回。如果不存在奇数，则返回一个空字符串 "" 。

子字符串 是字符串中的一个连续的字符序列。
*/
class Solution {
public:
	//找到右边最后一个奇数
	string largestOddNumber(string num) {
		int k = num.size() - 1;
		while (k >= 0 && num[k] % 2 == 0) k--;
		if (k < 0) return "";
		return num.substr(0, k + 1);
	}

};