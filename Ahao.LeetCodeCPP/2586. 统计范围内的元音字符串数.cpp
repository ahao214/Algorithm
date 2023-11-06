#include<vector>
#include<string>

using namespace std;

/*
2586. 统计范围内的元音字符串数

给你一个下标从 0 开始的字符串数组 words 和两个整数：left 和 right 。

如果字符串以元音字母开头并以元音字母结尾，那么该字符串就是一个 元音字符串 ，其中元音字母是 'a'、'e'、'i'、'o'、'u' 。

返回 words[i] 是元音字符串的数目，其中 i 在闭区间 [left, right] 内。
*/

class Solution {
public:
	int vowelStrings(vector<string>& words, int left, int right) {
		const string vowel = "aeiou";
		int ans = 0;
		for (int i = left; i <= right; i++) {
			string& s = words[i];
			ans += vowel.find(s[0]) != string::npos &&
				vowel.find(s.back()) != string::npos;
		}
		return ans;
	}
};
