#include<vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

/*
2465. ��ͬ��ƽ��ֵ��Ŀ

����һ���±�� 0 ��ʼ����Ϊ ż�� ���������� nums ��

ֻҪ nums ���� �����飬����ظ�ִ�����²��裺

�ҵ� nums �е���Сֵ����ɾ������
�ҵ� nums �е����ֵ����ɾ������
����ɾ��������ƽ��ֵ��
���� a �� b �� ƽ��ֵ Ϊ (a + b) / 2 ��

�ȷ�˵��2 �� 3 ��ƽ��ֵ�� (2 + 3) / 2 = 2.5 ��
�������������ܵõ��� ��ͬ ƽ��ֵ����Ŀ��

ע�� �������Сֵ�������ֵ���ظ�Ԫ�أ�����ɾ������һ����
*/

class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_set<int> seen;
        for (int i = 0, j = nums.size() - 1; i < j; ++i, --j) {
            seen.insert(nums[i] + nums[j]);
        }
        return seen.size();
    }
};
