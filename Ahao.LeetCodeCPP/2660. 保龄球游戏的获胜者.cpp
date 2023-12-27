#include<vector>
#include<string>

using namespace std;

/*
2660. ��������Ϸ�Ļ�ʤ��

���������±�� 0 ��ʼ���������� player1 �� player2 ���ֱ��ʾ��� 1 ����� 2 ���е�ƿ����

����������� n ����ɣ�ÿ�ֵ�ƿ��ǡ��Ϊ 10 ��

��������ڵ� i ���л��� xi ��ƿ�ӡ���ҵ� i �ֵļ�ֵΪ��

�������ڸ��ֵ�ǰ���ֵ��κ�һ���л����� 10 ��ƿ�ӣ���Ϊ 2xi ��
����Ϊ xi ��
��ҵĵ÷����� n �ּ�ֵ���ܺ͡�
*/

class Solution {
public:
    int score(const vector<int>& player) {
        int res = 0;
        for (int i = 0; i < player.size(); i++) {
            if ((i > 0 && player[i - 1] == 10) || (i > 1 && player[i - 2] >= 10)) {
                res += 2 * player[i];
            }
            else {
                res += player[i];
            }
        }
        return res;
    }

    int isWinner(vector<int>& player1, vector<int>& player2) {
        int s1 = score(player1);
        int s2 = score(player2);
        return s1 == s2 ? 0 : s1 > s2 ? 1 : 2;
    }
};
