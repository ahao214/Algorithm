#include<vector>

using namespace std;


/*
1958. 检查操作是否合法
*/
class Solution {
public:
	bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
		int n = board.size(), m = board[0].size();
		int dx[8] = { -1,-1,0,1,1,1,0,-1 };
		int dy[8] = { 0,1,1,1,0,-1,-1,-1 };
		for (int i = 0; i < 8; i++)
		{
			int x = rMove + dx[i], y = cMove + dy[i];
			int state = 0;
			while (x >= 0 && x < n && y >= 0 && y < m)
			{
				if (board[x][y] == '.')break;
				if (board[x][y] != color) state = 1;
				else
				{
					if (!state) break;
					return true;
				}
				x += dx[i], y += dy[i];
			}
		}
		return false;
	}
};


