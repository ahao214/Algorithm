#include<vector>
#include<string>

using namespace std;



/*
1728. 猫和老鼠 II
一只猫和一只老鼠在玩一个叫做猫和老鼠的游戏。

它们所处的环境设定是一个 rows x cols 的方格 grid ，其中每个格子可能是一堵墙、一块地板、一位玩家（猫或者老鼠）或者食物。

玩家由字符 'C' （代表猫）和 'M' （代表老鼠）表示。
地板由字符 '.' 表示，玩家可以通过这个格子。
墙用字符 '#' 表示，玩家不能通过这个格子。
食物用字符 'F' 表示，玩家可以通过这个格子。
字符 'C' ， 'M' 和 'F' 在 grid 中都只会出现一次。
猫和老鼠按照如下规则移动：

老鼠 先移动 ，然后两名玩家轮流移动。
每一次操作时，猫和老鼠可以跳到上下左右四个方向之一的格子，他们不能跳过墙也不能跳出 grid 。
catJump 和 mouseJump 是猫和老鼠分别跳一次能到达的最远距离，它们也可以跳小于最大距离的长度。
它们可以停留在原地。
老鼠可以跳跃过猫的位置。
游戏有 4 种方式会结束：

如果猫跟老鼠处在相同的位置，那么猫获胜。
如果猫先到达食物，那么猫获胜。
如果老鼠先到达食物，那么老鼠获胜。
如果老鼠不能在 1000 次操作以内到达食物，那么猫获胜。
给你 rows x cols 的矩阵 grid 和两个整数 catJump 和 mouseJump ，双方都采取最优策略，如果老鼠获胜，那么请你返回 true ，否则返回 false 。
*/

int f[8][8][8][8][200];
class Solution {
public:
	int n, m, cj, mj;
	vector<string> g;
	int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };

	int dp(int cx, int cy, int mx, int my, int k)
	{
		if (k >= 200) return 0;
		auto& v = f[cx][cy][mx][my][k];
		if (v != -1) return v;

		if (k & 1)
		{
			//猫
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j <= cj; j++)
				{
					int x = cx + dx[i] * j, y = cy + dy[i] * j;
					if (x < 0 || x >= n || y < 0 || y >= m || g[x][y] == '#') break;
					if (x == mx && y == my) return v = 0;
					if (g[x][y] == 'F') return v = 0;
					if (!dp(x, y, mx, my, k + 1)) return v = 0;
				}
			}
			return v = 1;
		}
		else
		{
			//老鼠
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j <= mj; j++)
				{
					int x = mx + dx[i] * j, y = my + dy[i] * j;
					if (x < 0 || x >= n || y < 0 || y >= m || g[x][y] == '#') break;
					if (x == cx && y == cy) continue;
					if (g[x][y] == 'F') return v = 1;
					if (dp(cx, cy, x, y, k + 1)) return v = 1;
				}
			}
			return v = 0;
		}
	}

	bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
		g = grid;
		n = g.size(), m = g[0].size(), cj = catJump, mj = mouseJump;
		int cx, cy, mx, my;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (g[i][j] == 'C') cx = i, cy = j;
				else if (g[i][j] == 'M') mx = i, my = j;

		memset(f, -1, sizeof f);
		return dp(cx, cy, mx, my, 0);
	}
};


