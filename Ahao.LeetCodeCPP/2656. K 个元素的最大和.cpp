#include<vector>
#include <algorithm>

using namespace std;

/*
2656. K ��Ԫ�ص�����

����һ���±�� 0 ��ʼ���������� nums ��һ������ k ������Ҫִ�����²��� ǡ�� k �Σ������ĵ÷֣�

�� nums ��ѡ��һ��Ԫ�� m ��
��ѡ�е�Ԫ�� m ��������ɾ����
����Ԫ�� m + 1 ��ӵ������С�
��ĵ÷����� m ��
���㷵��ִ�����ϲ���ǡ�� k �κ�����÷֡�
*/

class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int m = *max_element(nums.begin(), nums.end());
        return (2 * m + k - 1) * k / 2;
    }
};

