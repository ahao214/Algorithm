#include<vector>

using namespace std;



/*
2180. ͳ�Ƹ�λ����֮��Ϊż������������
����һ�������� num ������ͳ�Ʋ����� С�ڻ���� num �Ҹ�λ����֮��Ϊ ż�� ������������Ŀ��

�������� ��λ����֮�� ��������λ�ϵĶ�Ӧ������ӵĽ����
*/
class Solution {
public:
    int countEven(int num) {
        int ans = 0;
        for (int i = 1; i <= num; ++i) {
            int tmp = 0;
            int x = i;
            while (x) {
                tmp += x % 10;
                x /= 10;
            }
            if (tmp % 2 == 0)
                ++ans;
        }
        return ans;
    }
};