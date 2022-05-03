#include <string>
using namespace std;


class Solution {
	/*
	389. 找不同
	给定两个字符串 s 和 t ，它们只包含小写字母。

	字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。

	请找出在 t 中被添加的字母。
	*/
public:
	char findTheDifference(string s, string t) {
		char res = 0;
		for (auto c : s)
			res ^= c;
		for (auto c : t)
			res ^= c;
		return res;
	}
};