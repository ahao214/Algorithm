using namespace std;
#include<vector>
#include<string>
#include<unordered_map>

class Solution {
	/*
	30. 串联所有单词的子串
	给定一个字符串 s 和一些 长度相同 的单词 words 。
	找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。

	注意子串要与 words 中的单词完全匹配，中间不能有其他字符 ，
	但不需要考虑 words 中单词串联的顺序。
	*/
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> ans;
		if (words.empty()) return ans;

		int n = s.length(), m = words.size(), w = words[0].length();

		unordered_map<string, int> total;
		for (int i = 0; i < words.size(); i++) {
			total[words[i]]++;
		}

		for (int i = 0; i < w; i++) {
			unordered_map<string, int> window;
			int cnt = 0;
			for (int j = i; j + w <= n; j += w) {
				if (j - i >= m * w) {
					string word = s.substr(j - m * w, w);
					window[word]--;
					if (window[word] < total[word])
						cnt--;
				}
				string word = s.substr(j, w);
				window[word]++;
				if (window[word] <= total[word])
					cnt++;
				if (cnt == m)
					ans.push_back(j - (m - 1) * w);
			}
		}
		return ans;
	}
};