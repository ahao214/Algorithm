#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;


/*
1553. 吃掉 N 个橘子的最少天数
厨房里总共有 n 个橘子，你决定每一天选择如下方式之一吃这些橘子：

吃掉一个橘子。
如果剩余橘子数 n 能被 2 整除，那么你可以吃掉 n/2 个橘子。
如果剩余橘子数 n 能被 3 整除，那么你可以吃掉 2*(n/3) 个橘子。
每天你只能从以上 3 种方案中选择一种方案。

请你返回吃掉所有 n 个橘子的最少天数。
*/
class Solution {
public:
	unordered_map<int, int> d;
	queue<int> q;

	void extend(int dist, int x)
	{
		if (d.count(x)) return;
		d[x] = dist + 1;
		q.push(x);
	}

	int minDays(int n) {
		q.push(n);
		d[n] = 1;
		if (n == 1) return 1;
		while (q.size())
		{
			auto t = q.front();
			if (t == 1) return d[t];
			q.pop();
			extend(d[t], t - 1);
			if (t % 2 == 0) extend(d[t], t / 2);
			if (t % 3 == 0) extend(d[t], t / 3);
		}
		return -1;
	}
};