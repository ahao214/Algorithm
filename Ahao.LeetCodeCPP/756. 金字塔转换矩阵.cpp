#include<vector>
#include <string>

using namespace std;



/*
756. 金字塔转换矩阵
现在，我们用一些方块来堆砌一个金字塔。 每个方块用仅包含一个字母的字符串表示。

使用三元组表示金字塔的堆砌规则如下：

对于三元组 ABC ，C 为顶层方块，方块 A 、B 分别作为方块 C 下一层的的左、右子块。当且仅当 ABC 是被允许的三元组，我们才可以将其堆砌上。

初始时，给定金字塔的基层 bottom，用一个字符串表示。一个允许的三元组列表 allowed，每个三元组用一个长度为 3 的字符串表示。

如果可以由基层一直堆到塔尖就返回 true ，否则返回 false 。
*/
class Solution {
public:
	vector<char> allows[7][7];
	bool pyramidTransition(string bottom, vector<string>& allowed) {
		for (auto allow : allowed)
		{
			int a = allow[0] - 'A', b = allow[1] - 'A', c = allow[2];
			allows[a][b].push_back(c);
		}
		return dfs(bottom, "");
	}

	bool dfs(string& last, string now)
	{
		if (last.size() == 1) return true;

		if (now.size() + 1 == last.size()) return dfs(now, "");
		int a = last[now.size()] - 'A', b = last[now.size() + 1] - 'A';
		for (auto c : allows[a][b])
		{
			if (dfs(last, now + c))
				return true;
		}
		return false;
	}
};





class Solution {
public:
	vector<char> g[7][7];

	bool pyramidTransition(string bottom, vector<string>& allowed) {
		for (auto& e : allowed)
			g[e[0] - 'A'][e[1] - 'A'].push_back(e[2]);
		return dfs(bottom, "", 0);
	}

	bool dfs(string bottom, string cur, int u)
	{
		if (bottom.size() == 1)
			return true;
		if (u == bottom.size() - 1)
			return dfs(cur, "", 0);
		for (auto c : g[bottom[u] - 'A'][bottom[u + 1] - 'A'])
		{
			if (dfs(bottom, cur + c, u + 1))
				return true;
		}
		return false;
	}
};

