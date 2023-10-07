#include<vector>
#include <string>

using namespace std;


/*
131. �ָ���Ĵ�

����һ���ַ��� s�����㽫 s �ָ��һЩ�Ӵ���ʹÿ���Ӵ����� ���Ĵ� ������ s ���п��ܵķָ����

���Ĵ� �����Ŷ��ͷ��Ŷ���һ�����ַ�����
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



class Solution {
	int n;
	vector<vector<bool>> f;
	vector<vector<string>> ans;
	vector<string> path;
public:
	vector<vector<string>> partition(string s) {
		n = s.length();
		f = vector<vector<bool>>(n, vector<bool>(n));
		for (int j = 0; j < n; j++)
		{
			for (int i = 0; i <= j; i++)
			{
				if (i == j) f[i][j] = true;
				else
					f[i][j] = (s[i] == s[j]) && (i + 1 > j - 1 || f[i + 1][j - 1]);
			}
		}
		dfs(s, 0);
		return ans;
	}

	void dfs(string& s, int idx)
	{
		if (idx == n)
		{
			ans.push_back(path);
			return;
		}
		for (int i = idx; i < n; i++)
		{
			if (!f[idx][i]) continue;
			path.push_back(s.substr(idx, i - idx + 1));
			dfs(s, i + 1);
			path.pop_back();
		}
	}
};
