#include<vector>


using namespace std;


/*
1144. �ݼ�Ԫ��ʹ����ʾ��״

����һ���������� nums��ÿ�� ���� �����ѡ��һ��Ԫ�ز� ����Ԫ�ص�ֵ���� 1��

��������������֮һ�������� A ���� ������飺

ÿ��ż��������Ӧ��Ԫ�ض��������ڵ�Ԫ�أ��� A[0] > A[1] < A[2] > A[3] < A[4] > ...
���ߣ�ÿ������������Ӧ��Ԫ�ض��������ڵ�Ԫ�أ��� A[0] < A[1] > A[2] < A[3] > A[4] < ...
���ؽ����� nums ת��Ϊ��������������С����������
*/

class Solution {
public:
    int help(vector<int>& nums, int pos) {
        int res = 0;
        for (int i = pos; i < nums.size(); i += 2) {
            int a = 0;
            if (i - 1 >= 0) {
                a = max(a, nums[i] - nums[i - 1] + 1);
            }
            if (i + 1 < nums.size()) {
                a = max(a, nums[i] - nums[i + 1] + 1);
            }
            res += a;
        }
        return res;
    }

    int movesToMakeZigzag(vector<int>& nums) {
        return min(help(nums, 0), help(nums, 1));
    }
};
