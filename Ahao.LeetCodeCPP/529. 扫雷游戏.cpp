#include<vector>
#include<algorithm>


using namespace std;


/*
529. 扫雷游戏

让我们一起来玩扫雷游戏！

给你一个大小为 m x n 二维字符矩阵 board ，表示扫雷游戏的盘面，其中：

'M' 代表一个 未挖出的 地雷，
'E' 代表一个 未挖出的 空方块，
'B' 代表没有相邻（上，下，左，右，和所有4个对角线）地雷的 已挖出的 空白方块，
数字（'1' 到 '8'）表示有多少地雷与这块 已挖出的 方块相邻，
'X' 则表示一个 已挖出的 地雷。
给你一个整数数组 click ，其中 click = [clickr, clickc] 表示在所有 未挖出的 方块（'M' 或者 'E'）中的下一个点击位置（clickr 是行下标，clickc 是列下标）。

根据以下规则，返回相应位置被点击后对应的盘面：

如果一个地雷（'M'）被挖出，游戏就结束了- 把它改为 'X' 。
如果一个 没有相邻地雷 的空方块（'E'）被挖出，修改它为（'B'），并且所有和其相邻的 未挖出 方块都应该被递归地揭露。
如果一个 至少与一个地雷相邻 的空方块（'E'）被挖出，修改它为数字（'1' 到 '8' ），表示相邻地雷的数量。
如果在此次点击中，若无更多方块可被揭露，则返回盘面。
*/
class Solution {
public:
	int n, m;
	vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
		n = board.size(), m = board[0].size();
		int x = click[0], y = click[1];
		if (board[x][y] == 'M')
		{
			board[x][y] = 'X';
			return board;
		}
		dfs(board, x, y);
		return board;
	}

	void dfs(vector<vector<char>>& board, int x, int y)
	{
		if (board[x][y] != 'E') return;
		int s = 0;
		for (int i = max(x - 1, 0); i <= min(n - 1, x + 1); i++)
		{
			for (int j = max(y - 1, 0); j <= min(m - 1, y + 1); j++)
			{
				if (i != x || j != y)
					if (board[i][j] == 'M' || board[i][j] == 'X')
						s++;
			}
		}
		if (s)
		{
			board[x][y] = '0' + s;
			return;
		}
		board[x][y] = 'B';
		for (int i = max(x - 1, 0); i <= min(n - 1, x + 1); i++)
		{
			for (int j = max(y - 1, 0); j <= min(m - 1, y + 1); j++)
			{
				if (i != x || j != y)
					dfs(board, i, j);
			}
		}
	}
};

