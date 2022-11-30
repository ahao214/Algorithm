#include<vector>
#include<string>

using namespace std;


/*
79. 单词搜索
给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
*/
class Solution {
public:
	/*
	Times:O()
	Space:O(1)
	*/
	int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };
	bool exist(vector<vector<char>>& board, string word) {
		for (int i = 0; i < board.size(); i++)
			for (int j = 0; j < board[0].size(); j++)
			{
				if (dfs(board, word, 0, i, j))
					return true;
			}
		return false;
	}

	bool dfs(vector<vector<char>>& board, string& word, int idx, int x, int y)
	{
		if (board[x][y] != word[idx])
			return false;
		if (idx == word.length() - 1)
			return true;
		char t = board[x][y];
		board[x][y] = '.';
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size() || board[nx][ny] == '.')
				continue;
			if (dfs(board, word, idx + 1, nx, ny))
				return true;
		}
		board[x][y] = t;
		return false;
	}
};




/*
79. 单词搜索
给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
*/
class Solution {
public:
	int n, m;
	int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
	bool exist(vector<vector<char>>& board, string word)
	{
		if (board.empty() || board[0].empty()) return false;
		n = board.size(), m = board[0].size();

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (dfs(board, i, j, word, 0))
					return true;
			}
		}
		return false;
	}

	bool dfs(vector<vector<char>>& board, int x, int y, string& word, int u)
	{
		if (board[x][y] != word[u]) return false;
		if (u == word.size() - 1) return true;
		board[x][y] = '.';
		for (int i = 0; i < 4; i++)
		{
			int a = x + dx[i], b = y + dy[i];
			if (a >= 0 && a < n && b >= 0 && b < m)
				if (dfs(board, a, b, word, u + 1))
					return true;
		}
		board[x][y] = word[u];
		return false;
	}
};