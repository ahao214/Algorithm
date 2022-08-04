#include<vector>
#include<string>

using namespace std;


/*
2055. 蜡烛之间的盘子
给你一个长桌子，桌子上盘子和蜡烛排成一列。给你一个下标从 0 开始的字符串 s ，它只包含字符 '*' 和 '|' ，其中 '*' 表示一个 盘子 ，'|' 表示一支 蜡烛 。

同时给你一个下标从 0 开始的二维整数数组 queries ，其中 queries[i] = [lefti, righti] 表示 子字符串 s[lefti...righti] （包含左右端点的字符）。对于每个查询，你需要找到 子字符串中 在 两支蜡烛之间 的盘子的 数目 。如果一个盘子在 子字符串中 左边和右边 都 至少有一支蜡烛，那么这个盘子满足在 两支蜡烛之间 。

比方说，s = "||**||**|*" ，查询 [3, 8] ，表示的是子字符串 "*||**|" 。子字符串中在两支蜡烛之间的盘子数目为 2 ，子字符串中右边两个盘子在它们左边和右边 都 至少有一支蜡烛。
请你返回一个整数数组 answer ，其中 answer[i] 是第 i 个查询的答案。
*/
class Solution {
public:
	vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
		int n = s.size();
		vector<int> str(n + 1), left(n + 1), right(n + 2, n + 1);
		for (int i = 1; i <= n; i++)
		{
			str[i] = str[i - 1];
			if (s[i - 1] == '*') str[i]++, left[i] = left[i - 1];
			else left[i] = i;
		}
		for (int i = n; i; i--)
			if (s[i - 1] == '*') right[i] = right[i + 1];
			else right[i] = i;

		vector<int> res;
		for (auto& q : queries)
		{
			int a = right[q[0] + 1], b = left[q[1] + 1];
			if (a > b) res.push_back(0);
			else res.push_back(str[b] - str[a - 1]);
		}
		return res;
	}
};