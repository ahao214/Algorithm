#include<vector>

using namespace std;


/*
2651. �����г���վʱ��

����һ�������� arrivalTime ��ʾ�г����㵽վ��ʱ�䣨��λ��Сʱ���������һ�������� delayedTime ��ʾ�г������Сʱ����

�����г�ʵ�ʵ�վ��ʱ�䡣

ע�⣬�������е�ʱ����� 24 Сʱ�ơ�
*/

class Solution {
public:
    int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
        return (arrivalTime + delayedTime) % 24;
    }
};
