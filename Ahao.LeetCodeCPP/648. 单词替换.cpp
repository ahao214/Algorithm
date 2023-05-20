#include<vector>
#include <string>
#include <unordered_set>

using namespace std;

/*
648. 单词替换

在英语中，我们有一个叫做 词根(root) 的概念，可以词根后面添加其他一些词组成另一个较长的单词——我们称这个词为 继承词(successor)。例如，词根an，跟随着单词 other(其他)，可以形成新的单词 another(另一个)。

现在，给定一个由许多词根组成的词典 dictionary 和一个用空格分隔单词形成的句子 sentence。你需要将句子中的所有继承词用词根替换掉。如果继承词有许多可以形成它的词根，则用最短的词根替换它。

你需要输出替换之后的句子。
*/

class Solution {
public:
	string replaceWords(vector<string>& dictionary, string sentence) {
		typedef unsigned long long ULL;
		const int p = 131;
		unordered_set<ULL> hash;
		for (auto& s : dictionary)
		{
			ULL h = 0;
			for (auto c : s) h = h * p + c;
			hash.insert(h);
		}

		stringstream ssin(sentence);
		string res, word;
		while (ssin >> word)
		{
			string s;
			ULL h = 0;
			for (auto c : word)
			{
				s += c;
				h = h * p + c;
				if (hash.count(h))
					break;
			}
			res += s + ' ';
		}
		res.pop_back();
		return res;
	}
};