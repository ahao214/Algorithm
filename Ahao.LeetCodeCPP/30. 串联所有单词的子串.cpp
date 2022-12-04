using namespace std;
#include<vector>
#include<string>
#include<unordered_map>


/*
30. 串联所有单词的子串
给定一个字符串 s 和一些 长度相同 的单词 words 。
找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。

注意子串要与 words 中的单词完全匹配，中间不能有其他字符 ，
但不需要考虑 words 中单词串联的顺序。
*/
class Solution {
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





/*
30. 串联所有单词的子串
给定一个字符串 s 和一些 长度相同 的单词 words 。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。

注意子串要与 words 中的单词完全匹配，中间不能有其他字符 ，但不需要考虑 words 中单词串联的顺序。
*/
class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> res;
		int n = s.size(), m = words.size(), w = words[0].size();
		unordered_map<string, int> hashmap;
		for (int i = 0; i < m; i++) hashmap[words[i]]++;
		for (int i = 0; i < w; i++)
		{
			unordered_map<string, int> tdict;
			int sum = 0;
			int l = i;
			for (int j = l; j + w <= n; j += w)
			{
				string word;
				if (j - m * w >= l)
				{
					word = s.substr(j - m * w, w);
					if (tdict[word] == hashmap[word]) sum -= hashmap[word];
					tdict[word]--;
					if (tdict[word] == hashmap[word]) sum += hashmap[word];
				}
				word = s.substr(j, w);
				if (hashmap.count(word) == 0)
				{
					sum = 0;
					tdict.clear();
					l = j + w;
				}
				else
				{
					if (tdict[word] == hashmap[word]) sum -= hashmap[word];
					tdict[word]++;
					if (tdict[word] == hashmap[word]) sum += hashmap[word];
				}
				if (sum == m) res.push_back(j - (m - 1) * w);
			}
		}
		return res;
	}
};