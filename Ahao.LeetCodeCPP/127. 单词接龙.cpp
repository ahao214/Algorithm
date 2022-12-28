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