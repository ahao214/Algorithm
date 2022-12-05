#include<vector>
#include <string>

using namespace std;


/*
131. 分割回文串
给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。

回文串 是正着读和反着读都一样的字符串。
*/
class Solution {
public:
	vector<vector<string>> ans;
	vector<string> path;

	vector<vector<string>> partition(string s) {
		dfs("", 0, s);
		return ans;
	}

	bool check(string& now)
	{
		if (now.empty()) return false;
		for (int i = 0, j = now.size() - 1; i < j; i++, j--)
		{
			if (now[i] != now[j])
				return false;
		}
		return true;
	}

	void dfs(string now, int u, string& s)
	{
		if (u == s.size())
		{
			if (check(now))
			{
				path.push_back(now);
				ans.push_back(path);
				path.pop_back();
			}
			return;
		}

		if (check(now))
		{
			path.push_back(now);
			dfs("", u, s);
			path.pop_back();
		}
		dfs(now + s[u], u + 1, s);
	}
};
