#include<vector>

using namespace std;



/*
201. ���ַ�Χ��λ��
������������ left �� right ����ʾ���� [left, right]
���ش��������������� ��λ�� �Ľ�������� left ��right �˵㣩��
*/
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if (left == 0)
            return 0;
        while (left < right)
        {
            right &= (right - 1);
        }
        return right;
    }
};