#include<vector>
#include<string>
#include<unordered_set>

using namespace std;


/*
472. 连接词

给你一个 不含重复 单词的字符串数组 words ，请你找出并返回 words 中的所有 连接词 。

连接词 定义为：一个完全由给定数组中的至少两个较短单词（不一定是不同的两个单词）组成的字符串。
*/
class Solution {
public:
	unordered_set<string> hash;

	bool check(string& word)
	{
		int n = word.size();
		vector<int> f(n + 1, INT_MIN);
		f[0] = 0;
		for (int i = 0; i <= n; i++)
		{
			if (f[i] < 0) continue;
			for (int j = n - i; j; j--)
			{
				if (hash.count(word.substr(i, j)))
				{
					f[i + j] = max(f[i + j], f[i] + 1);
					if (f[n] > 1) return true;
				}
			}
		}
		return f[n] > 1;
	}

	vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
		for (auto& word : words)
			hash.insert(word);
		vector<string> res;
		for (auto& word : words)
		{
			if (check(word))
				res.push_back(word);
		}
		return res;
	}
};