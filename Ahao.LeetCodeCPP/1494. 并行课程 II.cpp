#include<vector>


using namespace std;



/*
1494. 并行课程 II

给你一个整数 n 表示某所大学里课程的数目，编号为 1 到 n ，数组 dependencies 中， dependencies[i] = [xi, yi]  表示一个先修课的关系，也就是课程 xi 必须在课程 yi 之前上。同时你还有一个整数 k 。

在一个学期中，你 最多 可以同时上 k 门课，前提是这些课的先修课在之前的学期里已经上过了。

请你返回上完所有课最少需要多少个学期。题目保证一定存在一种上完所有课的方式。
*/
class Solution {
public:
	const int INF = 1000;
	vector<int> f;
	int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
		f = vector<int>(1 << n, INF);
		for (auto& e : relations) e[0]--, e[1]--;

		f[0] = 0;
		for (int i = 0; i < 1 << n; i++)
		{
			vector<bool> st(n);
			for (auto& e : relations)
			{
				int x = e[0], y = e[1];
				if (!(i >> x & 1))
					st[y] = true;
			}
			int state = 0;
			for (int j = 0; j < n; j++)
				if (!st[j] && !(i >> j & 1))
					state += 1 << j;
			dfs(n, k, i, state, 0, 0);
		}
		return f[(1 << n) - 1];
	}

	void dfs(int n, int k, int i, int state, int now, int start) {
		if (!k || !state) {
			f[i | now] = min(f[i | now], f[i] + 1);
			return;
		}

		for (int j = start; j < n; j++)
		{
			if (state >> j & 1)
			{
				dfs(n, k - 1, i, state - (1 << j), now + (1 << j), j + 1);
			}
		}
	}
};



class Solution {
public:
	int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
		vector<int> dp(1 << n, INT_MAX);
		vector<int> need(1 << n, 0);
		for (auto& edge : relations) {
			need[(1 << (edge[1] - 1))] |= 1 << (edge[0] - 1);
		}
		dp[0] = 0;
		for (int i = 1; i < (1 << n); ++i) {
			need[i] = need[i & (i - 1)] | need[i & (-i)];
			if ((need[i] | i) != i) { // i 中有任意一门课程的前置课程没有完成学习
				continue;
			}
			int valid = i ^ need[i]; // 当前学期可以进行学习的课程集合
			if (__builtin_popcount(valid) <= k) { // 如果个数小于 k，则可以全部学习，不再枚举子集
				dp[i] = min(dp[i], dp[i ^ valid] + 1);
			}
			else { // 否则枚举当前学期需要进行学习的课程集合
				for (int sub = valid; sub; sub = (sub - 1) & valid) {
					if (__builtin_popcount(sub) <= k) {
						dp[i] = min(dp[i], dp[i ^ sub] + 1);
					}
				}
			}
		}
		return dp[(1 << n) - 1];
	}
};

