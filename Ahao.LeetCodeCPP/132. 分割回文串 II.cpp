#include<string>
#include<vector>

using namespace std;


/*
132. 分割回文串 II
*/
//时间O(N^2) 空间O(N^2)
class Solution {
public:
	int minCut(string s) {
		int n = s.length();
		vector<vector<bool>>g(n, vector<bool>(n));
		for (int j = 0; j < n; j++)
		{
			for (int i = 0; i <= j; i++)
			{
				if (i == j)
					g[i][j] = true;
				else
					g[i][j] = (s[i] == s[j]) && (i + 1 > j - 1 || g[i + 1][j - 1]);
			}
		}

		vector<int> f(n, INT_MAX);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				if (!g[j][i]) continue;
				if (j == 0) f[i] = 0;
				else
					f[i] = min(f[i], f[j - 1] + 1);
			}
		}
		return f[n - 1];
	}
};