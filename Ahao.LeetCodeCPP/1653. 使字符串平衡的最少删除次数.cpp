#include<vector>
#include<string>

using namespace std;


/*
1653. 使字符串平衡的最少删除次数
给你一个字符串 s ，它仅包含字符 'a' 和 'b'​​​​ 。

你可以删除 s 中任意数目的字符，使得 s 平衡 。我们称 s 平衡的 当不存在下标对 (i,j) 满足 i < j 且 s[i] = 'b' 同时 s[j]= 'a' 。

请你返回使 s 平衡 的 最少 删除次数。
*/
class Solution {
public:
	int minimumDeletions(string s) {
		int n = s.size();
		vector<int> s1(n + 1), s2(n + 1);
		for (int i = 1; i <= n; i++)
		{
			s1[i] = s1[i - 1];
			s2[i] = s2[i - 1];
			if (s[i - 1] == 'a') s1[i]++;
			else s2[i]++;
		}

		int res = INT_MAX;
		for (int i = 0; i <= n; i++)
		{
			res = min(res, s2[i] + s1[n] - s1[i]);
		}
		return res;
	}
};