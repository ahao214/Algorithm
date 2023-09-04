#include<vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

/*
2605. ����������������������С����

��������ֻ���� 1 �� 9 ֮�����ֵ����� nums1 �� nums2 ��ÿ�������е�Ԫ�� ������ͬ �����㷵�� ��С �����֣��������鶼 ���� ����������ֵ�ĳ����λ��
*/



class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        auto same = [&]() -> int {
            unordered_set<int> s(nums1.begin(), nums1.end());
            int x = 10;
            for (int num : nums2) {
                if (s.count(num)) {
                    x = min(x, num);
                }
            }
            return x == 10 ? -1 : x;
        };

        if (int x = same(); x != -1) {
            return x;
        }

        int x = *min_element(nums1.begin(), nums1.end());
        int y = *min_element(nums2.begin(), nums2.end());
        return min(x * 10 + y, y * 10 + x);
    }
};
