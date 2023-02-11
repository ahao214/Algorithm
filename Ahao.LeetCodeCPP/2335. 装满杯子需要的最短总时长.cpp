#include<vector>
#include <algorithm>
#include <numeric>

using namespace std;


/*
2335. װ��������Ҫ�������ʱ��

����һ̨��ˮ���������Ʊ���ˮ����ˮ����ˮ��ÿ���ӣ�����װ�� 2 �� ��ͬ ���͵�ˮ���� 1 ���������͵�ˮ��

����һ���±�� 0 ��ʼ������Ϊ 3 ���������� amount ������ amount[0]��amount[1] �� amount[2] �ֱ��ʾ��Ҫװ����ˮ����ˮ����ˮ�ı�������������װ�����б�������� ���� ������
*/


class Solution {
public:
    int fillCups(vector<int>& amount) {
        sort(amount.begin(), amount.end());
        if (amount[2] > amount[1] + amount[0]) {
            return amount[2];
        }
        return (accumulate(amount.begin(), amount.end(), 0) + 1) / 2;
    }
};

