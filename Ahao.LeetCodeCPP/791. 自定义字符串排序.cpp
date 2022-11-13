#include<string>
#include <vector>
#include <algorithm>

using namespace std;


/*
791. 自定义字符串排序

给定两个字符串 order 和 s 。order 的所有单词都是 唯一 的，并且以前按照一些自定义的顺序排序。

对 s 的字符进行置换，使其与排序的 order 相匹配。更具体地说，如果在 order 中的字符 x 出现字符 y 之前，那么在排列后的字符串中， x 也应该出现在 y 之前。

返回 满足这个性质的 s 的任意排列 。
*/

class Solution {
public:
	string customSortString(string order, string s) {
		vector<int> val(26);
		for (int i = 0; i < order.size(); ++i) {
			val[order[i] - 'a'] = i + 1;
		}
		sort(s.begin(), s.end(), [&](char c0, char c1) {
			return val[c0 - 'a'] < val[c1 - 'a'];
			});
		return s;
	}
};


//计数排序
class Solution {
public:
	string customSortString(string order, string s) {
		vector<int> freq(26);
		for (char ch : s) {
			++freq[ch - 'a'];
		}
		string ans;
		for (char ch : order) {
			if (freq[ch - 'a'] > 0) {
				ans += string(freq[ch - 'a'], ch);
				freq[ch - 'a'] = 0;
			}
		}
		for (int i = 0; i < 26; ++i) {
			if (freq[i] > 0) {
				ans += string(freq[i], i + 'a');
			}
		}
		return ans;
	}
};
