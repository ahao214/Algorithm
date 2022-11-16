#include<vector>

using namespace std;


/*
775. ȫ�ֵ�����ֲ�����

����һ������Ϊ n ���������� nums ����ʾ�ɷ�Χ [0, n - 1] ������������ɵ�һ�����С�

ȫ�ֵ��� ����Ŀ������������������ͬ�±�� (i, j) ����Ŀ��

0 <= i < j < n
nums[i] > nums[j]
�ֲ����� ����Ŀ�������������������±� i ����Ŀ��

0 <= i < n - 1
nums[i] > nums[i + 1]
������ nums �� ȫ�ֵ��� ���������� �ֲ����� ������ʱ������ true �����򣬷��� false ��
*/

class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size(), minSuff = nums[n - 1];
        for (int i = n - 3; i >= 0; i--) {
            if (nums[i] > minSuff) {
                return false;
            }
            minSuff = min(minSuff, nums[i + 1]);
        }
        return true;
    }
};
