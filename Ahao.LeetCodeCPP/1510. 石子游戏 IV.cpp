#include<vector>

using namespace std;


/*
1510. 石子游戏 IV
Alice 和 Bob 两个人轮流玩一个游戏，Alice 先手。

一开始，有 n 个石子堆在一起。每个人轮流操作，正在操作的玩家可以从石子堆里拿走 任意 非零 平方数 个石子。

如果石子堆里没有石子了，则无法操作的玩家输掉游戏。

给你正整数 n ，且已知两个人都采取最优策略。如果 Alice 会赢得比赛，那么返回 True ，否则返回 False 。
*/
class Solution {
public:
	bool winnerSquareGame(int n) {
		vector<bool> f(n + 1);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j * j <= i; j++)
			{
				if (f[i - j * j] == false)
				{
					f[i] = true;
					break;
				}
			}
		}
		return f[n];
	}
};