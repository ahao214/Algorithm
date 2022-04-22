using namespace std;
#include<vector>

class Solution {
	/*
	36. 有效的数独
	请你判断一个 9 x 9 的数独是否有效。
	只需要根据以下规则,验证已经填入的数字是否有效即可。

	数字 1-9 在每一行只能出现一次。
	数字 1-9 在每一列只能出现一次。
	数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
	*/
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		bool ex[9];

		//检查行
		for (int i = 0; i < 9; i++) {
			memset(ex, 0, sizeof(ex));
			for (int j = 0; j < 9; j++) {
				if (board[i][j] == '.') continue;
				int t = board[i][j] - '1';
				if (ex[t]) return false;
				ex[t] = true;
			}
		}

		//检查列
		for (int i = 0; i < 9; i++) {
			memset(ex, 0, sizeof(ex));
			for (int j = 0; j < 9; j++) {
				if (board[j][i] == '.') continue;
				int t = board[j][i] - '1';
				if (ex[t]) return false;
				ex[t] = true;
			}
		}

		//检查宫格内
		for (int i = 0; i < 9; i += 3) {
			for (int j = 0; j < 9; j += 3) {
				memset(ex, 0, sizeof(ex));
				for (int x = 0; x < 3; x++) {
					for (int y = 0; y < 3; y++) {
						if (board[i + x][j + y] == '.') continue;
						int t = board[i + x][j + y] - '1';
						if (ex[t]) return false;
						ex[t] = true;
					}
				}
			}
		}
		return true;
	}
};

