#include<string>
#include<vector>


using namespace std;

class Solution {
public:
	int maxLengthBetweenEqualCharacters(string s) {
		vector<int> firstIndex(26, -1);
		int maxLength = -1;
		for (int i = 0; i < s.size(); i++) {
			if (firstIndex[s[i] - 'a'] < 0) {
				firstIndex[s[i] - 'a'] = i;
			}
			else {
				maxLength = max(maxLength, i - firstIndex[s[i] - 'a'] - 1);
			}
		}
		return maxLength;
	}
};




/*
1624. 两个相同字符之间的最长子字符串
给你一个字符串 s，请你返回 两个相同字符之间的最长子字符串的长度 ，计算长度时不含这两个字符。如果不存在这样的子字符串，返回 -1 。

子字符串 是字符串中的一个连续字符序列。
*/
class Solution {
public:
	int maxLengthBetweenEqualCharacters(string s) {
		int res = -1;
		for (char c = 'a'; c <= 'z'; c++)
		{
			int left = s.size(), right = 0;
			for (int i = 0; i < s.size(); i++)
			{
				if (s[i] == c)
				{
					left = min(left, i);
					right = max(right, i);
				}
			}
			res = max(res, right - left - 1);
		}
		return res;
	}
};
