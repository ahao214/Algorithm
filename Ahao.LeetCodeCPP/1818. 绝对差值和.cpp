#include<vector>
#include <algorithm>

using namespace std;



/*
1818. 绝对差值和

给你两个正整数数组 nums1 和 nums2 ，数组的长度都是 n 。

数组 nums1 和 nums2 的 绝对差值和 定义为所有 |nums1[i] - nums2[i]|（0 <= i < n）的 总和（下标从 0 开始）。

你可以选用 nums1 中的 任意一个 元素来替换 nums1 中的 至多 一个元素，以 最小化 绝对差值和。

在替换数组 nums1 中最多一个元素 之后 ，返回最小绝对差值和。因为答案可能很大，所以需要对 109 + 7 取余 后返回。

|x| 定义为：

如果 x >= 0 ，值为 x ，或者
如果 x <= 0 ，值为 -x
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