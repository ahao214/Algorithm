#include<vector>

using namespace std;


/*
2413. ��Сż����

����һ�������� n ������ 2 �� n ����С������������������
*/


class Solution {
public:
    int smallestEvenMultiple(int n) {
        return n % 2 == 0 ? n : 2 * n;
    }
};
