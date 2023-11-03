#include<vector>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;



/*
127. 单词接龙
字典 wordList 中从单词 beginWord 和 endWord 的 转换序列 是一个按下述规格形成的序列 beginWord -> s1 -> s2 -> ... -> sk：

每一对相邻的单词只差一个字母。
 对于 1 <= i <= k 时，每个 si 都在 wordList 中。注意， beginWord 不需要在 wordList 中。
sk == endWord
给你两个单词 beginWord 和 endWord 和一个字典 wordList ，返回 从 beginWord 到 endWord 的 最短转换序列 中的 单词数目 。如果不存在这样的转换序列，返回 0 。
*/
class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		queue<string> q;
		unordered_set<string> wordSet(wordList.begin(), wordList.end());
		if (!wordSet.count(endWord))
		{
			return 0;
		}
		q.push(beginWord);
		int level = 1;
		while (!q.empty())
		{
			int size = q.size();
			for (int i = 0; i < size; i++)
			{
				string cur = q.front();
				q.pop();
				if (cur == endWord)
					return level;
				wordSet.erase(cur);
				for (int j = 0; j < cur.size(); j++)
				{
					char tmp = cur[j];
					for (int k = 0; k < 26; k++)
					{
						cur[j] = 'a' + k;
						if (wordSet.count(cur))
						{
							q.push(cur);
						}
					}
					cur[j] = tmp;
				}
			}
			level++;
		}
		return 0;
	}
};





class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> dict(wordList.begin(), wordList.end());
		if (!dict.count(endWord)) return 0;

		unordered_set<string> s1{ beginWord }, s2{ endWord };

		int step = 1;
		while (!s1.empty() && !s2.empty())
		{
			step++;
			if (s1.size() > s2.size()) swap(s1, s2);

			for (string w : s1) dict.erase(w);
			for (string w : s2) dict.erase(w);

			unordered_set<string> s;
			for (string word : s1)
			{
				for (int i = 0; i < word.length(); i++)
				{
					char ch = word[i];
					for (char j = 'a'; j <= 'z'; j++)
					{
						word[i] = j;
						if (s2.count(word)) return step;
						if (!dict.count(word)) continue;
						s.insert(word);
					}
					word[i] = ch;
				}
			}
			s1 = s;
		}
		return 0;
	}
};