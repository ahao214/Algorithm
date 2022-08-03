#include<vector>

using namespace std;


/*
2151. 基于陈述统计最多好人数
游戏中存在两种角色：

好人：该角色只说真话。
坏人：该角色可能说真话，也可能说假话。
给你一个下标从 0 开始的二维整数数组 statements ，大小为 n x n ，表示 n 个玩家对彼此角色的陈述。具体来说，statements[i][j] 可以是下述值之一：

0 表示 i 的陈述认为 j 是 坏人 。
1 表示 i 的陈述认为 j 是 好人 。
2 表示 i 没有对 j 作出陈述。
另外，玩家不会对自己进行陈述。形式上，对所有 0 <= i < n ，都有 statements[i][i] = 2 。

根据这 n 个玩家的陈述，返回可以认为是 好人 的 最大 数目。
*/
class Solution {
public:
	int maximumGood(vector<vector<int>>& statements) {
		int n = statements.size();

		int res = 0;
		for (int i = 0; i < 1 << n; i++)
		{
			bool flag = true;
			for (int j = 0; j < n; j++)
			{
				for (int k = 0; k < n; k++)
				{
					if (statements[j][k] == 2)continue;
					if (i >> j & 1)
					{
						if ((i >> k & 1) != statements[j][k])
							flag = false;
					}
				}
			}
			if (flag)
			{
				int s = 0;
				for (int j = 0; j < n; j++)
					s += i >> j & 1;
				res = max(res, s);
			}
		}
		return res;
	}
};