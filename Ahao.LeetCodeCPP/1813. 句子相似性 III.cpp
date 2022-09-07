#include<string>
#include<vector>

using namespace std;


/*
1813. 句子相似性 III
一个句子是由一些单词与它们之间的单个空格组成，且句子的开头和结尾没有多余空格。比方说，"Hello World" ，"HELLO" ，"hello world hello world" 都是句子。每个单词都 只 包含大写和小写英文字母。

如果两个句子 sentence1 和 sentence2 ，可以通过往其中一个句子插入一个任意的句子（可以是空句子）而得到另一个句子，那么我们称这两个句子是 相似的 。比方说，sentence1 = "Hello my name is Jane" 且 sentence2 = "Hello Jane" ，我们可以往 sentence2 中 "Hello" 和 "Jane" 之间插入 "my name is" 得到 sentence1 。

给你两个句子 sentence1 和 sentence2 ，如果 sentence1 和 sentence2 是相似的，请你返回 true ，否则返回 false 。
*/
class Solution {
public:
	bool areSentencesSimilar(string sentence1, string sentence2) {
		if (sentence1.size() > sentence2.size())
			return areSentencesSimilar(sentence2, sentence1);
		stringstream s1(sentence1), s2(sentence2);
		vector<string>a, b;
		string s;
		while (s1 >> s) a.push_back(s);
		while (s2 >> s) b.push_back(s);

		int i = 0, j = a.size() - 1;
		for (int k = 0; k < b.size() && i < a.size(); k++)
			if (a[i] == b[k])
				i++;
			else
				break;
		for (int k = b.size() - 1; k >= 0 && j >= 0; k--)
			if (a[j] == b[k])
				j--;
			else
				break;
		return i > j;
	}

};
