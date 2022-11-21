#include<vector>
#include <string>

using namespace std;


/*
1520. 最多的不重叠子字符串
给你一个只包含小写字母的字符串 s ，你需要找到 s 中最多数目的非空子字符串，满足如下条件：

这些字符串之间互不重叠，也就是说对于任意两个子字符串 s[i..j] 和 s[k..l] ，要么 j < k 要么 i > l 。
如果一个子字符串包含字符 char ，那么 s 中所有 char 字符都应该在这个子字符串中。
请你找到满足上述条件的最多子字符串数目。如果有多个解法有相同的子字符串数目，请返回这些子字符串总长度最小的一个解。可以证明最小总长度解是唯一的。

请注意，你可以以 任意 顺序返回最优解的子字符串。
*/
class Solution {
public:
	vector<string> maxNumOfSubstrings(string s) {
		int n = s.size();
		s = ' ' + s;
		vector<vector<int>> sum(26, vector<int>(n + 1));
		vector<vector<int>> range(26, { INT_MAX,INT_MIN });
		for (int i = 1; i <= n; i++)
		{
			int t = s[i] - 'a';
			for (int j = 0; j < 26; j++)
			{
				sum[j][i] = sum[j][i - 1];
				if (j == t) sum[j][i]++;
			}
			range[t][0] = min(range[t][0], i);
			range[t][1] = max(range[t][1], i);
		}

		while (true)
		{
			bool flag = true;
			for (int i = 0; i < 26; i++)
			{
				auto cur = range[i];
				if (cur[0] > cur[1]) continue;
				for (int j = 0; j < 26; j++)
				{
					if (sum[j][cur[1]] - sum[j][cur[0] - 1])
					{
						cur[0] = min(cur[0], range[j][0]);
						cur[1] = max(cur[1], range[j][1]);
					}
				}
				if (cur != range[i])
				{
					range[i] = cur;
					flag = false;
				}
			}
			if (flag) break;
		}

		for (int i = 0; i < 26; i++)
		{
			for (int j = 0; j < 26; j++)
			{
				if (i != j && range[j][0] != INT_MAX && range[i][0] <= range[j][0] && range[i][1] >= range[j][1])
				{
					range[i] = { INT_MAX,INT_MIN };
				}
			}
		}
		vector<string> res;
		for (int i = 0; i < 26; i++)
		{
			int l = range[i][0], r = range[i][1];
			if (l <= r)
				res.push_back(s.substr(l, r - l + 1));
		}
		return res;
	}
};