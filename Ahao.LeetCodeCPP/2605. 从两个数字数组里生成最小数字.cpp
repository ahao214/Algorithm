#include<vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

/*
2605. 从两个数字数组里生成最小数字

给你两个只包含 1 到 9 之间数字的数组 nums1 和 nums2 ，每个数组中的元素 互不相同 ，请你返回 最小 的数字，两个数组都 至少 包含这个数字的某个数位。
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
