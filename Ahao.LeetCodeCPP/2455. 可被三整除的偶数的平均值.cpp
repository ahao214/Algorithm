#include<vector>

using namespace std;

/*
2455. �ɱ���������ż����ƽ��ֵ

����һ������������ɵ��������� nums ���������пɱ� 3 ����������ż����ƽ��ֵ��

ע�⣺n ��Ԫ�ص�ƽ��ֵ���� n ��Ԫ�� ��� �ٳ��� n ����� ����ȡ�� ����ӽ���������
*/

class Solution {
public:
    int averageValue(vector<int>& nums) {
        int total = 0, k = 0;
        for (int a : nums) {
            if (a % 6 == 0) {
                total += a;
                k++;
            }
        }
        return k > 0 ? total / k : 0;
    }
};

