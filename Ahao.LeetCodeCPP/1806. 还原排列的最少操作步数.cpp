#include<vector>

using namespace std;


/*
1806. 还原排列的最少操作步数
给你一个偶数 n​​​​​​ ，已知存在一个长度为 n 的排列 perm ，其中 perm[i] == i​（下标 从 0 开始 计数）。

一步操作中，你将创建一个新数组 arr ，对于每个 i ：

如果 i % 2 == 0 ，那么 arr[i] = perm[i / 2]
如果 i % 2 == 1 ，那么 arr[i] = perm[n / 2 + (i - 1) / 2]
然后将 arr​​ 赋值​​给 perm 。

要想使 perm 回到排列初始值，至少需要执行多少步操作？返回最小的 非零 操作步数。
*/
class Solution {
public:
	void work(vector<int>& q)
	{
		vector<int> w;
		for (int i = 0; i < q.size(); i += 2) w.push_back(q[i]);
		for (int i = 1; i < q.size(); i += 2) w.push_back(q[i]);
		q = w;
	}

	bool check(vector<int>& q)
	{
		for (int i = 0; i < q.size(); i++)
		{
			if (q[i] != i)
				return false;
		}
		return true;
	}

	int reinitializePermutation(int n) {
		vector<int> q;
		for (int i = 0; i < n; i++)
		{
			q.push_back(i);
		}
		int cnt = 0;
		while (true)
		{
			cnt++;
			work(q);
			if (check(q)) break;
		}
		return cnt;
	}
};
