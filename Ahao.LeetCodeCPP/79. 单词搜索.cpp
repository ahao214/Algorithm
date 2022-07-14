#include<vector>
#include<string>

using namespace std;
class Solution {
	/*
	79. ��������
	����һ�� m x n ��ά�ַ����� board ��һ���ַ������� word ����� word �����������У����� true �����򣬷��� false ��

	���ʱ��밴����ĸ˳��ͨ�����ڵĵ�Ԫ���ڵ���ĸ���ɣ����С����ڡ���Ԫ������Щˮƽ���ڻ�ֱ���ڵĵ�Ԫ��ͬһ����Ԫ���ڵ���ĸ�������ظ�ʹ�á�
	*/
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
