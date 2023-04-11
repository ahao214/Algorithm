#include<vector>
#include <string>

using namespace std;

/*
1041. ���ڻ��еĻ�����

�����޵�ƽ���ϣ����������λ�� (0, 0) �����泯������ע��:

������ ��y���������
�Ϸ��� ��y��ĸ�����
������ ��x���������
������ ��x��ĸ�����
�����˿��Խ�����������ָ��֮һ��

"G"��ֱ�� 1 ����λ
"L"����ת 90 ��
"R"����ת 90 ��
�����˰�˳��ִ��ָ�� instructions����һֱ�ظ����ǡ�

ֻ����ƽ���д��ڻ�ʹ�û�������Զ�޷��뿪ʱ������ true�����򣬷��� false��
*/


class Solution {
public:
    bool isRobotBounded(string instructions) {
        vector<vector<int>> direc{ {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
        int direcIndex = 0;
        int x = 0, y = 0;
        for (char instruction : instructions) {
            if (instruction == 'G') {
                x += direc[direcIndex][0];
                y += direc[direcIndex][1];
            }
            else if (instruction == 'L') {
                direcIndex += 3;
                direcIndex %= 4;
            }
            else {
                direcIndex++;
                direcIndex %= 4;
            }
        }
        return direcIndex != 0 || (x == 0 && y == 0);
    }
};
