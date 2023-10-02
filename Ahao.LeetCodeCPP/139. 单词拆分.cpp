#include<vector>
#include <string>
#include <unordered_set>

using namespace std;



/*
139. 单词拆分

给你一个字符串 s 和一个字符串列表 wordDict 作为字典。请你判断是否可以利用字典中出现的单词拼接出 s 。

注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。
*/
class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string> S;
		for (auto word : wordDict) S.insert(word);

		int n = s.size();
		vector<bool> f(n + 1, false);
		f[0] = true;

		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (S.count(s.substr(j, i - j)) && f[j] == true)
				{
					f[i] = true;
					break;
				}
			}
		}
		return f[n];
	}
};





class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string> st(wordDict.begin(), wordDict.end());

		int n = s.length();
		s = ' ' + s;
		vector<bool> f(n + 1);
		f[0] = true;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i; j > 0; j--)
				if (f[j - 1] && st.count(s.substr(j, i - j + 1)))
				{
					f[i] = true;
					break;
				}
		}
		return f[n];
	}
};
