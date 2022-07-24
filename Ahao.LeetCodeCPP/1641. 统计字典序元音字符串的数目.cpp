#include<vector>

using namespace std;



/*
1641. 统计字典序元音字符串的数目
*/
class Solution {
	int dp[51][5];
public:
	int countVowelStrings(int n) {
		for (int k = 0; k < 5; k++)
			dp[0][k] = 1;

		for (int i = 1; i < n; i++)
			for (int k = 0; k < 5; k++)
			{
				for (int j = 0; j <= k; j++)
					dp[i][k] += dp[i - 1][j];
			}
		int res = 0;
		for (int k = 0; k < 5; k++)
			res += dp[n - 1][k];
		return res;
	}
};


class Solution {
public:
	int countVowelStrings(int n) {
		return comb(n + 4, 4);
	}

	int comb(int n, int m)
	{
		long long cnt = 1;
		for (int i = 0; i < m; i++)
		{
			cnt *= n - i;
			cnt /= i + 1;
		}
		return cnt;
	}
};


