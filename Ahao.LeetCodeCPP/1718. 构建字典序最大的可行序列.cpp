#include<vector>

using namespace std;



/*
1718. 构建字典序最大的可行序列
给你一个整数 n ，请你找到满足下面条件的一个序列：

整数 1 在序列中只出现一次。
2 到 n 之间每个整数都恰好出现两次。
对于每个 2 到 n 之间的整数 i ，两个 i 之间出现的距离恰好为 i 。
序列里面两个数 a[i] 和 a[j] 之间的 距离 ，我们定义为它们下标绝对值之差 |j - i| 。

请你返回满足上述条件中 字典序最大 的序列。题目保证在给定限制条件下，一定存在解。

一个序列 a 被认为比序列 b （两者长度相同）字典序更大的条件是： a 和 b 中第一个不一样的数字处，a 序列的数字比 b 序列的数字大。比方说，[0,1,9,0] 比 [0,1,5,6] 字典序更大，因为第一个不同的位置是第三个数字，且 9 比 5 大。
*/
class Solution {
public:
	int m;
	vector<int> st;
	vector<int> path;

	bool dfs(int u)
	{
		if (u == m * 2 - 1) return true;
		if (path[u]) return dfs(u + 1);
		for (int i = m; i > 1; i--)
		{
			if (!st[i] && u + i < m * 2 - 1 && !path[u + i])
			{
				path[u] = path[u + i] = i;
				st[i] = true;
				if (dfs(u + 1)) return true;
				st[i] = false;
				path[u] = path[u + i] = 0;
			}
		}
		if (!st[1])
		{
			st[1] = true;
			path[u] = 1;
			if (dfs(u + 1)) return true;
			path[u] = 0;
			st[1] = false;
		}
		return false;
	}

	vector<int> constructDistancedSequence(int n) {
		m = n;
		st.resize(m + 1, false);
		path.resize(m * 2 - 1);
		dfs(0);
		return path;
	}
};

