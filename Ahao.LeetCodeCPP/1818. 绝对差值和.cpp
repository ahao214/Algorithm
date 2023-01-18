#include<vector>
#include <algorithm>

using namespace std;



/*
1818. ���Բ�ֵ��

������������������ nums1 �� nums2 ������ĳ��ȶ��� n ��

���� nums1 �� nums2 �� ���Բ�ֵ�� ����Ϊ���� |nums1[i] - nums2[i]|��0 <= i < n���� �ܺͣ��±�� 0 ��ʼ����

�����ѡ�� nums1 �е� ����һ�� Ԫ�����滻 nums1 �е� ���� һ��Ԫ�أ��� ��С�� ���Բ�ֵ�͡�

���滻���� nums1 �����һ��Ԫ�� ֮�� ��������С���Բ�ֵ�͡���Ϊ�𰸿��ܴܺ�������Ҫ�� 109 + 7 ȡ�� �󷵻ء�

|x| ����Ϊ��

��� x >= 0 ��ֵΪ x ������
��� x <= 0 ��ֵΪ -x
*/
class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2)
    {
        auto arr = nums1;
        sort(arr.begin(), arr.end());
        int n = nums2.size();
        int maxDecrease = 0;

        for (int i = 0; i < n; i++)
        {
            auto iter = lower_bound(arr.begin(), arr.end(), nums2[i]);
            int a = INT_MAX / 2, b = INT_MAX / 2;
            if (iter != arr.end())
                a = *iter;
            if (iter != arr.begin())
                b = *prev(iter);

            int diff = min(abs(a - nums2[i]), abs(b - nums2[i]));

            int origin = abs(nums1[i] - nums2[i]);
            maxDecrease = max(maxDecrease, origin - diff);
        }

        long ret = 0;
        long M = 1e9 + 7;
        for (int i = 0; i < n; i++)
        {
            ret = ret + abs((long)nums1[i] - (long)nums2[i]);
            ret %= M;
        }
        ret -= maxDecrease;
        ret = (ret + M) % M;

        return ret;
    }
};