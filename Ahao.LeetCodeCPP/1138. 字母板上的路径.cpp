#include<vector>

using namespace std;

/*
1138. ��ĸ���ϵ�·��

���Ǵ�һ����ĸ���ϵ�λ�� (0, 0) �������������Ӧ���ַ�Ϊ board[0][0]��

�ڱ������ĸ��Ϊboard = ["abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"]��������ʾ��



���ǿ��԰������ָ������ж���

���������ڣ�'U' ��ζ�Ž����ǵ�λ������һ�У�
���������ڣ�'D' ��ζ�Ž����ǵ�λ������һ�У�
���������ڣ�'L' ��ζ�Ž����ǵ�λ������һ�У�
���������ڣ�'R' ��ζ�Ž����ǵ�λ������һ�У�
'!' ��������ǵ�ǰλ�� (r, c) ���ַ� board[r][c] ��ӵ����С�
��ע�⣬��ĸ����ֻ��������ĸ��λ�á���

����ָ�����У�����С���ж������ô𰸺�Ŀ�� target ��ͬ������Է����κδ��Ŀ���·����
*/

class Solution {
public:
    string alphabetBoardPath(string target) {
        int cx = 0, cy = 0;
        string res;
        for (char c : target) {
            int nx = (c - 'a') / 5;
            int ny = (c - 'a') % 5;
            if (nx < cx) {
                res.append(cx - nx, 'U');
            }
            if (ny < cy) {
                res.append(cy - ny, 'L');
            }
            if (nx > cx) {
                res.append(nx - cx, 'D');
            }
            if (ny > cy) {
                res.append(ny - cy, 'R');
            }
            res.push_back('!');
            cx = nx;
            cy = ny;
        }
        return res;
    }
};