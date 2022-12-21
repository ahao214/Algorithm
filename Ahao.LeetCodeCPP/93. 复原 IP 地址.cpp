#include<vector>
#include <string>

using namespace std;



/*
93. 复原 IP 地址
有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。

例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。
给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。你 不能 重新排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。
*/
class Solution {
public:
	vector<string> res;
	vector<string> restoreIpAddresses(string s) {
		string path;
		dfs(s, 0, 0, path);
		return res;
	}

	void dfs(string& s, int u, int k, string path)
	{
		if (u == s.size())
		{
			if (k == 4)
			{
				res.push_back(path.substr(1));
			}
			return;
		}
		if (k > 4) return;

		if (s[u] == '0')
			dfs(s, u + 1, k + 1, path + ".0");
		else
		{
			for (int i = u, t = 0; i < s.size(); i++)
			{
				t = t * 10 + s[i] - '0';
				if (t < 256) dfs(s, i + 1, k + 1, path + '.' + to_string(t));
				else break;
			}
		}
	}
};
