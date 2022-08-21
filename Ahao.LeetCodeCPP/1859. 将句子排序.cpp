#include<string>
#include<vector>
#include<algorithm>

using namespace std;


/*
1859. 将句子排序
一个 句子 指的是一个序列的单词用单个空格连接起来，且开头和结尾没有任何空格。每个单词都只包含小写或大写英文字母。

我们可以给一个句子添加 从 1 开始的单词位置索引 ，并且将句子中所有单词 打乱顺序 。

比方说，句子 "This is a sentence" 可以被打乱顺序得到 "sentence4 a3 is2 This1" 或者 "is2 sentence4 This1 a3" 。
给你一个 打乱顺序 的句子 s ，它包含的单词不超过 9 个，请你重新构造并得到原本顺序的句子。
*/
class Solution {
public:
	string sortSentence(string s) {
		vector<pair<int, string>> q;
		for (int i = 0; i < s.size(); i++)
		{
			int j = i;
			string word;
			while (j < s.size() && s[j] != ' ')
				word += s[j++];
			i = j;
			q.push_back({ word.back() - '0',word.substr(0,word.size() - 1) });
		}
		sort(q.begin(), q.end());
		string res;
		for (auto& w : q)
		{
			res += w.second + ' ';
		}
		res.pop_back();
		return res;
	}

};
