#include<vector>


using namespace std;

/*
1281. �����ĸ�λ����֮��

����һ������ n�������æ���㲢���ظ���������λ����֮�����롸��λ����֮�͡��Ĳ
*/


class Solution {
public:
    int subtractProductAndSum(int n) {
        int add = 0, mul = 1;
        while (n > 0) {
            int digit = n % 10;
            n /= 10;
            add += digit;
            mul *= digit;
        }
        return mul - add;
    }
};
