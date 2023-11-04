#include<vector>
#include <string>
#include <unordered_map>

using namespace std;


/*
187. 重复的DNA序列

DNA序列 由一系列核苷酸组成，缩写为 'A', 'C', 'G' 和 'T'.。

例如，"ACGAATTCCG" 是一个 DNA序列 。
在研究 DNA 时，识别 DNA 中的重复序列非常有用。

给定一个表示 DNA序列 的字符串 s ，返回所有在 DNA 分子中出现不止一次的 长度为 10 的序列(子字符串)。你可以按 任意顺序 返回答案。
*/
class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		unordered_map<string, int> hash;
		vector<string> res;
		for (int i = 0; i + 10 <= s.size(); i++)
		{
			string str = s.substr(i, 10);
			if (++hash[str] == 2)
				res.push_back(str);
		}
		return res;
	}
};





class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		if (s.length() < 10)
			return {};
		vector<string> res;
		string sub = s.substr(0, 10);
		unordered_map<string, int> cnt{ {sub,1} };

		for (int i = 10; i < s.length(); i++) {
			sub += s[i];
			sub.erase(sub.begin());
			if (cnt[sub]++ == 1) {
				res.push_back(sub);
			}
		}
		return res;
	}
};


class Solution {
	const int L = 10;
	unordered_map<char, int> bin = { {'A', 0}, {'C', 1}, {'G', 2}, {'T', 3} };
public:
	vector<string> findRepeatedDnaSequences(string s) {
		vector<string> ans;
		int n = s.length();
		if (n <= L) {
			return ans;
		}
		int x = 0;
		for (int i = 0; i < L - 1; ++i) {
			x = (x << 2) | bin[s[i]];
		}
		unordered_map<int, int> cnt;
		for (int i = 0; i <= n - L; ++i) {
			x = ((x << 2) | bin[s[i + L - 1]]) & ((1 << (L * 2)) - 1);
			if (++cnt[x] == 2) {
				ans.push_back(s.substr(i, L));
			}
		}
		return ans;
	}
};


class Solution {
	const int L = 10;
public:
	vector<string> findRepeatedDnaSequences(string s) {
		vector<string> ans;
		unordered_map<string, int> cnt;
		int n = s.length();
		for (int i = 0; i <= n - L; ++i) {
			string sub = s.substr(i, L);
			if (++cnt[sub] == 2) {
				ans.push_back(sub);
			}
		}
		return ans;
	}
};

