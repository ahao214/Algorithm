#include<vector>

using namespace std;


/*
1883. 准时抵达会议现场的最小跳过休息次数
给你一个整数 hoursBefore ，表示你要前往会议所剩下的可用小时数。要想成功抵达会议现场，你必须途经 n 条道路。道路的长度用一个长度为 n 的整数数组 dist 表示，其中 dist[i] 表示第 i 条道路的长度（单位：千米）。另给你一个整数 speed ，表示你在道路上前进的速度（单位：千米每小时）。

当你通过第 i 条路之后，就必须休息并等待，直到 下一个整数小时 才能开始继续通过下一条道路。注意：你不需要在通过最后一条道路后休息，因为那时你已经抵达会议现场。

例如，如果你通过一条道路用去 1.4 小时，那你必须停下来等待，到 2 小时才可以继续通过下一条道路。如果通过一条道路恰好用去 2 小时，就无需等待，可以直接继续。
然而，为了能准时到达，你可以选择 跳过 一些路的休息时间，这意味着你不必等待下一个整数小时。注意，这意味着与不跳过任何休息时间相比，你可能在不同时刻到达接下来的道路。

例如，假设通过第 1 条道路用去 1.4 小时，且通过第 2 条道路用去 0.6 小时。跳过第 1 条道路的休息时间意味着你将会在恰好 2 小时完成通过第 2 条道路，且你能够立即开始通过第 3 条道路。
返回准时抵达会议现场所需要的 最小跳过次数 ，如果 无法准时参会 ，返回 -1 。
*/
const int N = 1010;
const double eps = 1e-8, INF = 1e9;
double f[N][N];

class Solution {
public:
	int minSkips(vector<int>& dist, int speed, int hoursBefore) {
		int n = dist.size();
		for (int i = 1; i <= n; i++)
		{
			double t = (double)dist[i - 1] / speed;
			for (int j = 0; j <= i; j++)
			{
				f[i][j] = INF;
				if (j <= i - 1)
					f[i][j] = ceil(f[i - 1][j] + t - eps);
				if (j)f[i][j] = min(f[i][j], f[i - 1][j - 1] + t);
			}
		}

		for (int i = 0; i <= n; i++)
		{
			if (f[n][i] <= hoursBefore)
				return i;
		}
		return -1;
	}
};

