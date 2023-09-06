using namespace std;
#include<vector>
#include<string>
#include <unordered_map>


/*
890. 查找和替换模式

你有一个单词列表 words 和一个模式  pattern，你想知道 words 中的哪些单词与模式匹配。

如果存在字母的排列 p ，使得将模式中的每个字母 x 替换为 p(x) 之后，我们就得到了所需的单词，那么单词与模式是匹配的。

（回想一下，字母的排列是从字母到字母的双射：每个字母映射到另一个字母，没有两个字母映射到同一个字母。）

返回 words 中与给定模式匹配的单词列表。

你可以按任何顺序返回答案。
*/


class Solution {
	bool match(string& word, string& pattern) {
		unordered_map<char, char> mp;
		for (int i = 0; i < word.length(); ++i) {
			char x = word[i], y = pattern[i];
			if (!mp.count(x)) {
				mp[x] = y;
			}
			else if (mp[x] != y) { // word 中的同一字母必须映射到 pattern 中的同一字母上
				return false;
			}
		}
		return true;
	}

public:
	vector<string> findAndReplacePattern(vector<string>& words, string& pattern) {
		vector<string> ans;
		for (auto& word : words) {
			if (match(word, pattern) && match(pattern, word)) {
				ans.emplace_back(word);
			}
		}
		return ans;
	}
};



class Solution {
	string p(string word)
	{
		unordered_map<char, int> dict;
		for (auto w : word)
		{
			if (!dict.count(w))
				dict[w] = dict.size();
		}
		for (int i = 0; i < word.size(); i++)
			word[i] = 'a' + dict[word[i]];
		return word;
	}
public:
	vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
		vector<string>res;
		string pa = p(pattern);
		for (auto word : words)
		{
			if (p(word) == pa)
			{
				res.push_back(word);
			}
		}
		return res;
	}
};
