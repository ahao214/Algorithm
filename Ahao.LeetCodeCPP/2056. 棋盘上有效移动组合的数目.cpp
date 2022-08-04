#include<vector>
#include<string>

using namespace std;


/*
2056. 棋盘上有效移动组合的数目
有一个 8 x 8 的棋盘，它包含 n 个棋子（棋子包括车，后和象三种）。给你一个长度为 n 的字符串数组 pieces ，其中 pieces[i] 表示第 i 个棋子的类型（车，后或象）。除此以外，还给你一个长度为 n 的二维整数数组 positions ，其中 positions[i] = [ri, ci] 表示第 i 个棋子现在在棋盘上的位置为 (ri, ci) ，棋盘下标从 1 开始。

棋盘上每个棋子都可以移动 至多一次 。每个棋子的移动中，首先选择移动的 方向 ，然后选择 移动的步数 ，同时你要确保移动过程中棋子不能移到棋盘以外的地方。棋子需按照以下规则移动：

车可以 水平或者竖直 从 (r, c) 沿着方向 (r+1, c)，(r-1, c)，(r, c+1) 或者 (r, c-1) 移动。
后可以 水平竖直或者斜对角 从 (r, c) 沿着方向 (r+1, c)，(r-1, c)，(r, c+1)，(r, c-1)，(r+1, c+1)，(r+1, c-1)，(r-1, c+1)，(r-1, c-1) 移动。
象可以 斜对角 从 (r, c) 沿着方向 (r+1, c+1)，(r+1, c-1)，(r-1, c+1)，(r-1, c-1) 移动。
移动组合 包含所有棋子的 移动 。每一秒，每个棋子都沿着它们选择的方向往前移动 一步 ，直到它们到达目标位置。所有棋子从时刻 0 开始移动。如果在某个时刻，两个或者更多棋子占据了同一个格子，那么这个移动组合 不有效 。

请你返回 有效 移动组合的数目。

注意：

初始时，不会有两个棋子 在 同一个位置 。
有可能在一个移动组合中，有棋子不移动。
如果两个棋子 直接相邻 且两个棋子下一秒要互相占据对方的位置，可以将它们在同一秒内 交换位置 。
*/
class Solution {
public:
	int n;
	vector<string> pc;
	vector<vector<int>> pt;
	int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
	int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
	vector<vector<int>> path;
	int ans = 0;
	int p[5][2];

	bool check() {
		for (int i = 0; i < n; i++) {
			p[i][0] = pt[i][0];
			p[i][1] = pt[i][1];
		}

		for (int i = 1; ; i++) {
			bool flag = false;
			for (int j = 0; j < n; j++) {
				int d = path[j][0], t = path[j][1];
				if (i <= t) {
					flag = true;
					p[j][0] += dx[d];
					p[j][1] += dy[d];
				}
			}
			if (!flag) break;

			for (int j = 0; j < n; j++)
				for (int k = j + 1; k < n; k++)
					if (p[j][0] == p[k][0] && p[j][1] == p[k][1])
						return false;
		}

		return true;
	}

	void dfs(int u) {
		if (u == n) {
			if (check()) ans++;
			return;
		}

		path.push_back({ 0, 0 });
		dfs(u + 1);
		path.pop_back();

		for (int i = 0; i < 8; i++) {
			string& s = pc[u];
			if (s == "rook" && i % 2) continue;
			if (s == "bishop" && i % 2 == 0) continue;
			int x = pt[u][0], y = pt[u][1];
			for (int j = 1; ; j++) {
				x += dx[i], y += dy[i];
				if (x < 1 || x > 8 || y < 1 || y > 8) break;
				path.push_back({ i, j });
				dfs(u + 1);
				path.pop_back();
			}
		}
	}

	int countCombinations(vector<string>& pieces, vector<vector<int>>& positions) {
		pc = pieces, pt = positions;
		n = pc.size();
		dfs(0);
		return ans;
	}

};