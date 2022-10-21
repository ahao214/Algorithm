#include<vector>
#include<string>

using namespace std;


/*
1737. 满足三条件之一需改变的最少字符数
给你两个字符串 a 和 b ，二者均由小写字母组成。一步操作中，你可以将 a 或 b 中的 任一字符 改变为 任一小写字母 。

操作的最终目标是满足下列三个条件 之一 ：

a 中的 每个字母 在字母表中 严格小于 b 中的 每个字母 。
b 中的 每个字母 在字母表中 严格小于 a 中的 每个字母 。
a 和 b 都 由 同一个 字母组成。
返回达成目标所需的 最少 操作数。
*/
class Solution {
public:
	int work(vector<int> s1, vector<int> s2)
	{
		//让s1中的字符小于s2中的字符
		int res = INT_MAX;
		for (int i = 1; i < 26; i++)
		{
			int cnt = 0;
			for (int j = i; j < 26; j++) cnt += s1[j];
			for (int j = 0; j < i; j++) cnt += s2[j];
			res = min(res, cnt);
		}
		return res;
	}

	int minCharacters(string a, string b) {
		vector<int> s1(26), s2(26);
		for (auto c : a) s1[c - 'a']++;
		for (auto c : b) s2[c - 'a']++;

		int n = a.size(), m = b.size();
		int res = INT_MAX;
		for (int i = 0; i < 26; i++)
		{
			res = min(res, n + m - (s1[i] + s2[i]));
		}
		return min(res, min(work(s1, s2), work(s2, s1)));
	}
};