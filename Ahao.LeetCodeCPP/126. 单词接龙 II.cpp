#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>


using namespace std;


/*
126. 单词接龙 II

按字典 wordList 完成从单词 beginWord 到单词 endWord 转化，一个表示此过程的 转换序列 是形式上像 beginWord -> s1 -> s2 -> ... -> sk 这样的单词序列，并满足：

每对相邻的单词之间仅有单个字母不同。
转换过程中的每个单词 si（1 <= i <= k）必须是字典 wordList 中的单词。注意，beginWord 不必是字典 wordList 中的单词。
sk == endWord
给你两个单词 beginWord 和 endWord ，以及一个字典 wordList 。请你找出并返回所有从 beginWord 到 endWord 的 最短转换序列 ，如果不存在这样的转换序列，返回一个空列表。每个序列都应该以单词列表 [beginWord, s1, s2, ..., sk] 的形式返回。
*/
class Solution {
	unordered_map<string, vector<string>> children;
	vector<vector<string>> ans;
	vector<string> path;
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> dict(wordList.begin(), wordList.end());
		if (!dict.count(endWord)) return ans;

		unordered_set<string> s1{ beginWord }, s2{ endWord };

		bool found = false, beginToEnd = true;

		while (!s1.empty() && !s2.empty() && !found)
		{
			if (s1.size() > s2.size())
			{
				swap(s1, s2);
				beginToEnd = !beginToEnd;
			}

			for (string w : s1) dict.erase(w);
			for (string w : s2) dict.erase(w);

			unordered_set<string> s;
			for (string word : s1)
			{
				string cur = word;
				for (int i = 0; i < word.size(); i++)
				{
					char ch = word[i];
					for (char j = 'a'; j <= 'z'; j++)
					{
						word[i] = j;
						string parent = cur, child = word;
						if (!beginToEnd)
							swap(parent, child);
						if (s2.count(word))
						{
							found = true;
							children[parent].push_back(child);
						}
						else if (dict.count(word) && !found)
						{
							s.insert(word);
							children[parent].push_back(child);
						}
					}
					word[i] = ch;
				}
			}
			s1 = s;
		}
		if (found)
		{
			path.push_back(beginWord);
			dfs(beginWord, endWord);
		}
		return ans;
	}

	void dfs(string word, string endWord)
	{
		if (word == endWord)
		{
			ans.push_back(path);
			return;
		}
		for (string child : children[word])
		{
			path.push_back(child);
			dfs(child, endWord);
			path.pop_back();
		}
	}
};

