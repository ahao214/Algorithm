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


class Solution {
public:
    int countEven(int num) {
        int res = 0;
        for (int i = 1; i <= num; i++) {
            int x = i, sum = 0;
            while (x) {
                sum += x % 10;
                x /= 10;
            }
            if (sum % 2 == 0) {
                res++;
            }
        }
        return res;
    }
};
