#include<vector>
#include<string>

using namespace std;


/*
1915. 最美子字符串的数目
如果某个字符串中 至多一个 字母出现 奇数 次，则称其为 最美 字符串。

例如，"ccjjc" 和 "abab" 都是最美字符串，但 "ab" 不是。
给你一个字符串 word ，该字符串由前十个小写英文字母组成（'a' 到 'j'）。请你返回 word 中 最美非空子字符串 的数目。如果同样的子字符串在 word 中出现多次，那么应当对 每次出现 分别计数。

子字符串 是字符串中的一个连续字符序列。
*/
typedef long long LL;
const int N = 100010;
int s[N][10];
int cnt[1024];

class Solution {
public:
	long long wonderfulSubstrings(string word) {
		int n = word.size();
		LL res = 0;
		memset(cnt, 0, sizeof cnt);
		cnt[0]++;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (word[i - 1] - 'a' == j) s[i][j] = s[i - 1][j] + 1;
				else s[i][j] = s[i - 1][j];
			}
			int state = 0;
			for (int j = 0; j < 10; j++)
			{
				state = state * 2 + s[i][j] % 2;
			}
			res += cnt[state];
			for (int j = 0; j < 10; j++)
				res += cnt[state ^ (1 << j)];
			cnt[state]++;
		}
		return res;
	}
};


