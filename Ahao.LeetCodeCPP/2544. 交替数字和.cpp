#include<vector>

using namespace std;

/*
2544. �������ֺ�

����һ�������� n ��n �е�ÿһλ���ֶ��ᰴ�����������һ�����ţ�

�����Чλ �ϵ����ַ��䵽 �� �š�
ʣ��ÿλ�����ֵķ��Ŷ��������������෴��
�����������ּ����Ӧ���ŵĺ͡�
*/


class Solution {
public:
    int alternateDigitSum(int n) {
        int res = 0, sign = 1;
        while (n > 0) {
            res += n % 10 * sign;
            sign = -sign;
            n /= 10;
        }
        return -sign * res;
    }
};