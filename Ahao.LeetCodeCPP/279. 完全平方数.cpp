#include<vector>
#include <queue>

using namespace std;


/*
279. 完全平方数
给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。

完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。
例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。
*/
class Solution {
public:
	int numSquares(int n) {
		queue<int> q;
		vector<int>dist(n + 1, INT_MAX);
		q.push(0);
		dist[0] = 0;
		while (q.size()) {
			int t = q.front();
			q.pop();
			if (t == n) return dist[t];
			for (int i = 1; i * i + t <= n; i++) {
				int j = t + i * i;
				if (dist[j] > dist[t] + 1) {
					dist[j] = dist[t] + 1;
					q.push(j);
				}
			}
		}
		return 0;
	}
};