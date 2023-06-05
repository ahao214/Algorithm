#include<vector>

using namespace std;

/*
2460. ������ִ�в���

����һ���±�� 0 ��ʼ������ nums �������СΪ n ������ �Ǹ� ������ɡ�

����Ҫ������ִ�� n - 1 �����������е� i ���������� 0 ��ʼ������Ҫ��� nums �е� i ��Ԫ��ִ������ָ�

��� nums[i] == nums[i + 1] ���� nums[i] ��ֵ���ԭ���� 2 ����nums[i + 1] ��ֵ��� 0 �����������ⲽ������
��ִ���� ȫ�� �����󣬽����� 0 �ƶ� ������� ĩβ ��

���磬���� [1,0,2,0,0,1] ������ 0 �ƶ���ĩβ���Ϊ [1,2,1,0,0,0] ��
���ؽ�����顣

ע�� ����Ӧ�� �������� ִ�У�������һ����ȫ��ִ�С�
*/

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0, j = 0; i < n; i++) {
            if (i + 1 < n && nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
            if (nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
        return nums;
    }
};
