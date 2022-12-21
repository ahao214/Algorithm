#include<vector>
#include <ctype.h>
#include<string>
#include <queue>

using namespace std;

//方法一：广度优先搜索
class Solution {
public:
	vector<string> letterCasePermutation(string s) {
		vector<string> ans;
		queue<string> qu;
		qu.emplace("");
		while (!qu.empty()) {
			string& curr = qu.front();
			if (curr.size() == s.size()) {
				ans.emplace_back(curr);
				qu.pop();
			}
			else {
				int pos = curr.size();
				if (isalpha(s[pos])) {
					string next = curr;
					next.push_back(s[pos] ^ 32);
					qu.emplace(next);
				}
				curr.push_back(s[pos]);
			}
		}
		return ans;
	}
};



//方法二：回溯
class Solution {
public:
	void dfs(string& s, int pos, vector<string>& res) {
		while (pos < s.size() && isdigit(s[pos])) {
			pos++;
		}
		if (pos == s.size()) {
			res.emplace_back(s);
			return;
		}
		s[pos] ^= 32;
		dfs(s, pos + 1, res);
		s[pos] ^= 32;
		dfs(s, pos + 1, res);
	}

	vector<string> letterCasePermutation(string s) {
		vector<string> ans;
		dfs(s, 0, ans);
		return ans;
	}
};



//方法三：二进制位图
class Solution {
public:
	vector<string> letterCasePermutation(string s) {
		int n = s.size();
		int m = 0;
		for (auto c : s) {
			if (isalpha(c)) {
				m++;
			}
		}
		vector<string> ans;
		for (int mask = 0; mask < (1 << m); mask++) {
			string str;
			for (int j = 0, k = 0; j < n; j++) {
				if (isalpha(s[j]) && (mask & (1 << k++))) {
					str.push_back(toupper(s[j]));
				}
				else {
					str.push_back(tolower(s[j]));
				}
			}
			ans.emplace_back(str);
		}
		return ans;
	}
};




/*
784. 字母大小写全排列
给定一个字符串S，通过将字符串S中的每个字母转变大小写，我们可以获得一个新的字符串。返回所有可能得到的字符串集合。
*/
class Solution {
public:
	vector<string> res;
	vector<string> letterCasePermutation(string s) {
		dfs(s, 0);
		return res;
	}

	void dfs(string s, int u)
	{
		if (u == s.size())
		{
			res.push_back(s);
			return;
		}
		dfs(s, u + 1);
		if (s[u] >= 'A')
		{
			//转换大小写
			s[u] ^= 32;
			dfs(s, u + 1);
		}
	}
};