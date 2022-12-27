#include<vector>
#include <string>

using namespace std;

/*
2027. ת���ַ��������ٲ�������
����һ���ַ��� s ���� n ���ַ���ɣ�ÿ���ַ����� 'X' ���� 'O' ��

һ�� ���� ����Ϊ�� s ��ѡ�� ���������ַ� ����ѡ�е�ÿ���ַ���ת��Ϊ 'O' ��ע�⣬����ַ��Ѿ��� 'O' ��ֻ��Ҫ���� ���� ��

���ؽ� s �������ַ���ת��Ϊ 'O' ��Ҫִ�е� ���� ����������
*/

class Solution {
public:
    int minimumMoves(string s) {
        int covered = -1, res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'X' && i > covered) {
                res += 1;
                covered = i + 2;
            }
        }
        return res;
    }
};
