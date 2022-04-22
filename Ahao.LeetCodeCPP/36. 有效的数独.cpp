using namespace std;
#include<vector>

class Solution {
	/*
	36. ��Ч������
	�����ж�һ�� 9 x 9 �������Ƿ���Ч��
	ֻ��Ҫ�������¹���,��֤�Ѿ�����������Ƿ���Ч���ɡ�

	���� 1-9 ��ÿһ��ֻ�ܳ���һ�Ρ�
	���� 1-9 ��ÿһ��ֻ�ܳ���һ�Ρ�
	���� 1-9 ��ÿһ���Դ�ʵ�߷ָ��� 3x3 ����ֻ�ܳ���һ�Ρ�����ο�ʾ��ͼ��
	*/
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		bool ex[9];

		//�����
		for (int i = 0; i < 9; i++) {
			memset(ex, 0, sizeof(ex));
			for (int j = 0; j < 9; j++) {
				if (board[i][j] == '.') continue;
				int t = board[i][j] - '1';
				if (ex[t]) return false;
				ex[t] = true;
			}
		}

		//�����
		for (int i = 0; i < 9; i++) {
			memset(ex, 0, sizeof(ex));
			for (int j = 0; j < 9; j++) {
				if (board[j][i] == '.') continue;
				int t = board[j][i] - '1';
				if (ex[t]) return false;
				ex[t] = true;
			}
		}

		//��鹬����
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

