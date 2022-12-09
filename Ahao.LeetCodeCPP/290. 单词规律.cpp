#include<vector>
#include <string>
#include <unordered_map>

using namespace std;



/*
290. 单词规律
给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。

这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。
*/
class Solution {
public:
	bool wordPattern(string pattern, string s) {
		stringstream raw(s);
		vector<string> words;
		string word;
		while (raw >> word) words.push_back(word);
		unordered_map<char, string> ps;
		unordered_map<string, char> sp;
		if (pattern.size() != words.size()) return false;
		for (int i = 0; i < words.size(); i++)
		{
			char p = pattern[i];
			string str = words[i];
			if (!ps.count(p)) ps[p] = str;
			if (!sp.count(str)) sp[str] = p;
			if (ps[p] != str || sp[str] != p)return false;
		}
		return true;
	}
};
