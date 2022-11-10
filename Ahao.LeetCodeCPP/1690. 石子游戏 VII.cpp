#include<vector>

using namespace std;


/*
1690. 石子游戏 VII
石子游戏中，爱丽丝和鲍勃轮流进行自己的回合，爱丽丝先开始 。

有 n 块石子排成一排。每个玩家的回合中，可以从行中 移除 最左边的石头或最右边的石头，并获得与该行中剩余石头值之 和 相等的得分。当没有石头可移除时，得分较高者获胜。

鲍勃发现他总是输掉游戏（可怜的鲍勃，他总是输），所以他决定尽力 减小得分的差值 。爱丽丝的目标是最大限度地 扩大得分的差值 。

给你一个整数数组 stones ，其中 stones[i] 表示 从左边开始 的第 i 个石头的值，如果爱丽丝和鲍勃都 发挥出最佳水平 ，请返回他们 得分的差值 。
*/
class Solution {
public:
	int stoneGameVII(vector<int>& stones) {
		int n = stones.size();
		vector<int> s(n + 1);
		for (int i = 1; i <= n; i++)
			s[i] = s[i - 1] + stones[i - 1];
		vector<vector<int>> f(n + 1, vector<int>(n + 1));
		for (int len = 2; len <= n; len++)
		{
			for (int i = 1; i + len - 1 <= n; i++)
			{
				int j = i + len - 1;
				f[i][j] = max(s[j] - s[i] - f[i + 1][j], s[j - 1] - s[i - 1] - f[i][j - 1]);
			}
		}
		return f[1][n];
	}
};