#include<vector>

using namespace std;


/*
1563. 石子游戏 V
几块石子 排成一行 ，每块石子都有一个关联值，关联值为整数，由数组 stoneValue 给出。

游戏中的每一轮：Alice 会将这行石子分成两个 非空行（即，左侧行和右侧行）；Bob 负责计算每一行的值，即此行中所有石子的值的总和。Bob 会丢弃值最大的行，Alice 的得分为剩下那行的值（每轮累加）。如果两行的值相等，Bob 让 Alice 决定丢弃哪一行。下一轮从剩下的那一行开始。

只 剩下一块石子 时，游戏结束。Alice 的分数最初为 0 。

返回 Alice 能够获得的最大分数 。
*/
class Solution {
public:
	vector<int> s;
	int get(int left, int right)
	{
		return s[right] - s[left - 1];
	}

	int stoneGameV(vector<int>& stoneValue) {
		int n = stoneValue.size();
		s.resize(n + 1);
		for (int i = 1; i <= n; i++) s[i] = s[i - 1] + stoneValue[i - 1];

		vector<vector<int>> f(n + 1, vector<int>(n + 1));
		for (int len = 2; len <= n; len++)
		{
			for (int i = 1; i + len - 1 <= n; i++)
			{
				int j = i + len - 1, sum = get(i, j), k = i, p = stoneValue[i - 1];
				int t = 0;
				while (p < sum - p)
				{
					if (t < p + f[i][k]) t = p + f[i][k];
					p += stoneValue[k++];
				}
				if (p == sum - p)
				{
					if (t < p + max(f[i][k], f[k + 1][j]))
						t = p + max(f[i][k], f[k + 1][j]);
					p += stoneValue[k++];
				}
				while (k < j)
				{
					if (t < sum - p + f[k + 1][j])
						t = sum - p + f[k + 1][j];
					p += stoneValue[k++];
				}
				f[i][j] = t;
			}
		}
		return f[1][n];
	}
};
