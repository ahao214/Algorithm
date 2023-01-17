#include<vector>
#include <string>

using namespace std;


/*
438. 找到字符串中所有字母异位词

给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。
*/
class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		int m = s.size(), n = p.size();
		if (m < n) {
			return {};
		}
		vector<int> pCount(26, 0), sCount(26, 0);
		for (auto c : p) {
			pCount[c - 'a']++;
		}
		vector<int> res;
		for (int i = 0; i < m; ++i) {
			sCount[s[i] - 'a']++;
			if (i >= n) {
				sCount[s[i - n] - 'a']--;
			}
			if (sCount == pCount) {
				res.push_back(i - n + 1);
			}
		}
		return res;
	}
};
