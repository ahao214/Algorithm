#include<vector>
#include <string>
#include <algorithm>

using namespace std;

/*
1451. 重新排列句子中的单词
「句子」是一个用空格分隔单词的字符串。给你一个满足下述格式的句子 text :

句子的首字母大写
text 中的每个单词都用单个空格分隔。
请你重新排列 text 中的单词，使所有单词按其长度的升序排列。如果两个单词的长度相同，则保留其在原句子中的相对顺序。

请同样按上述格式返回新的句子。
*/
class Solution {
public:
	string arrangeWords(string text) {
		stringstream ssin(text);
		vector<string> words;
		string word;
		while (ssin >> word) words.push_back(word);
		words[0][0] = tolower(words[0][0]);
		stable_sort(words.begin(), words.end(), [](string a, string b) {
			return a.size() < b.size();
			});
		words[0][0] = toupper(words[0][0]);

		string res;
		for (auto word : words) res += word + ' ';
		res.pop_back();
		return res;
	}
};