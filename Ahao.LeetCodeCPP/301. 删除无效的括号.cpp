#include<vector>
#include<string>

using namespace std;



/*
301. ɾ����Ч������

����һ�����������ź���ĸ��ɵ��ַ��� s ��ɾ����С��������Ч���ţ�ʹ��������ַ�����Ч��

�������п��ܵĽ�����𰸿��԰� ����˳�� ���ء�
*/
class Solution {
public:
	vector<string> ans;

	vector<string> removeInvalidParentheses(string s) {
		int left = 0, right = 0;
		for (auto x : s)
		{
			if (x == '(') left++;
			else if (x == ')')
			{
				if (left == 0)right++;
				else left--;
			}
		}
		dfs(s, 0, "", 0, left, right);
		return ans;
	}

	void dfs(string& s, int u, string path, int cnt, int left, int right)
	{
		if (u == s.size())
		{
			if (!cnt) ans.push_back(path);
			return;
		}
		if (s[u] != '(' && s[u] != ')')
			dfs(s, u + 1, path + s[u], cnt, left, right);
		else if (s[u] == '(')
		{
			int k = u;
			while (k < s.size() && s[k] == '(')k++;
			left -= k - u;
			for (int i = k - u; i >= 0; i--)
			{
				if (left >= 0)
					dfs(s, k, path, cnt, left, right);
				path += '(';
				cnt++, left++;
			}
		}
		else if (s[u] == ')')
		{
			int k = u;
			while (k < s.size() && s[k] == ')')k++;
			right -= k - u;
			for (int i = k - u; i >= 0; i--)
			{
				if (cnt >= 0 && right >= 0)
					dfs(s, k, path, cnt, left, right);
				path += ')';
				cnt--, right++;
			}
		}
	}
};
