#include<vector>
#include<algorithm>


using namespace std;


/*
529. ɨ����Ϸ

������һ������ɨ����Ϸ��

����һ����СΪ m x n ��ά�ַ����� board ����ʾɨ����Ϸ�����棬���У�

'M' ����һ�� δ�ڳ��� ���ף�
'E' ����һ�� δ�ڳ��� �շ��飬
'B' ����û�����ڣ��ϣ��£����ң�������4���Խ��ߣ����׵� ���ڳ��� �հ׷��飬
���֣�'1' �� '8'����ʾ�ж��ٵ�������� ���ڳ��� �������ڣ�
'X' ���ʾһ�� ���ڳ��� ���ס�
����һ���������� click ������ click = [clickr, clickc] ��ʾ������ δ�ڳ��� ���飨'M' ���� 'E'���е���һ�����λ�ã�clickr �����±꣬clickc �����±꣩��

�������¹��򣬷�����Ӧλ�ñ�������Ӧ�����棺

���һ�����ף�'M'�����ڳ�����Ϸ�ͽ�����- ������Ϊ 'X' ��
���һ�� û�����ڵ��� �Ŀշ��飨'E'�����ڳ����޸���Ϊ��'B'�����������к������ڵ� δ�ڳ� ���鶼Ӧ�ñ��ݹ�ؽ�¶��
���һ�� ������һ���������� �Ŀշ��飨'E'�����ڳ����޸���Ϊ���֣�'1' �� '8' ������ʾ���ڵ��׵�������
����ڴ˴ε���У����޸��෽��ɱ���¶���򷵻����档
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

