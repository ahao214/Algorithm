using namespace std;
#include<vector>



class Solution {
	/*
	37. ������
	��дһ������ͨ�����ո�������������⡣

	�����Ľⷨ�� ��ѭ���¹���

	���� 1-9 ��ÿһ��ֻ�ܳ���һ�Ρ�
	���� 1-9 ��ÿһ��ֻ�ܳ���һ�Ρ�
	���� 1-9 ��ÿһ���Դ�ʵ�߷ָ��� 3x3 ����ֻ�ܳ���һ�Ρ�����ο�ʾ��ͼ��
	�������ֿո��������������֣��հ׸��� '.' ��ʾ��
	*/
	bool rows[9][9], cols[9][9], cells[3][3][9];
public:
	void solveSudoku(vector<vector<char>>& board) {
		memset(rows, 0, sizeof(rows));
		memset(cols, 0, sizeof(cols));
		memset(cells, 0, sizeof(cells));
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] == '.') continue;
				int t = board[i][j] - '1';
				rows[i][t] = cols[j][t] = cells[i / 3][j / 3][t] = true;
			}
		}
		dfs(board, 0, 0);
	}

	bool dfs(vector<vector<char>>& board, int x, int y) {
		if (y == 9) x++, y = 0;
		if (x == 9) return true;
		if (board[x][y] != '.') return dfs(board, x, y + 1);

		for (int i = 0; i < 9; i++) {
			if (rows[x][i] || cols[y][i] || cells[x / 3][y / 3][i]) continue;
			board[x][y] = i + '1';
			rows[x][i] = cols[y][i] = cells[x / 3][y / 3][i] = true;
			if (dfs(board, x, y + 1)) return true;
			rows[x][i] = cols[y][i] = cells[x / 3][y / 3][i] = false;
			board[x][y] = '.';
		}
		return false;
	}
};