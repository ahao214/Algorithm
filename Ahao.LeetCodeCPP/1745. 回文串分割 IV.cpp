#include<vector>
#include<string>

using namespace std;


/*
1745. 回文串分割 IV
给你一个字符串 s ，如果可以将它分割成三个 非空 回文子字符串，那么返回 true ，否则返回 false 。

当一个字符串正着读和反着读是一模一样的，就称其为 回文字符串 。
*/
class Solution {
public:
	bool checkPartitioning(string s) {
		int n = s.size();
		vector<vector<bool>> f(n, vector<bool>(n));
		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = i; j < n; j++)
			{
				if (i == j) f[i][j] = true;
				else if (i + 1 == j) f[i][j] = s[i] == s[j];
				else f[i][j] = s[i] == s[j] && f[i + 1][j - 1];
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j + 1 < n; j++)
			{
				if (f[0][i] && f[i + 1][j] && f[j + 1][n - 1])
					return true;
			}
		}
		return false;
	}
};