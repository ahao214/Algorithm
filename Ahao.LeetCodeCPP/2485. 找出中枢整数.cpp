#include<vector>

using namespace std;


/*
2485. �ҳ���������

����һ�������� n ���ҳ��������������� �������� x ��

1 �� x ֮�������Ԫ��֮�͵��� x �� n ֮������Ԫ��֮�͡�
������������ x ����������������������򷵻� -1 ����Ŀ��֤���ڸ��������룬�������һ������������
*/

class Solution {
public:
    int pivotInteger(int n) {
        int t = (n * n + n) / 2;
        int x = sqrt(t);
        if (x * x == t) {
            return x;
        }
        return -1;
    }
};

