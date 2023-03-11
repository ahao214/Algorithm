#include<vector>

using namespace std;

/*
754. �����յ�����

��һ�����޳��������ϣ���վ��0��λ�á��յ���target��λ�á�

�������һЩ�������ƶ� numMoves :

ÿ�������ѡ������������ƶ���
�� i ���ƶ�����  i == 1 ��ʼ���� i == numMoves ������ѡ��ķ������� i ����
�������� target ������ ����Ŀ������� ��С �ƶ�����(����С numMoves ) ��
*/


class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int k = 0;
        while (target > 0) {
            k++;
            target -= k;
        }
        return target % 2 == 0 ? k : k + 1 + k % 2;
    }
};


class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int n = 0, sum = 0;
        while (sum < target || (sum - target) % 2)
        {
            n++;
            sum += n;
        }
        return n;
    }
};