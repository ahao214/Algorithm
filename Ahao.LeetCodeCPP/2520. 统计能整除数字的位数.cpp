#include<vector>

using namespace std;

/*
2520. ͳ�����������ֵ�λ��

����һ������ num ������ num �������� num ����λ����Ŀ��

������� nums % val == 0 ������Ϊ���� val �������� nums ��
*/



class Solution {
public:
    int countDigits(int num) {
        int t = num, res = 0;
        while (t) {
            if (num % (t % 10) == 0) {
                res += 1;
            }
            t /= 10;
        }
        return res;
    }
};
