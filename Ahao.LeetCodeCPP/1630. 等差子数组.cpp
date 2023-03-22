#include<vector>
#include <algorithm>

using namespace std;

/*
1630. 等差子数组

如果一个数列由至少两个元素组成，且每两个连续元素之间的差值都相同，那么这个序列就是 等差数列 。更正式地，数列 s 是等差数列，只需要满足：对于每个有效的 i ， s[i+1] - s[i] == s[1] - s[0] 都成立。

例如，下面这些都是 等差数列 ：

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
下面的数列 不是等差数列 ：

1, 1, 2, 5, 7
给你一个由 n 个整数组成的数组 nums，和两个由 m 个整数组成的数组 l 和 r，后两个数组表示 m 组范围查询，其中第 i 个查询对应范围 [l[i], r[i]] 。所有数组的下标都是 从 0 开始 的。

返回 boolean 元素构成的答案列表 answer 。如果子数组 nums[l[i]], nums[l[i]+1], ... , nums[r[i]] 可以 重新排列 形成 等差数列 ，answer[i] 的值就是 true；否则answer[i] 的值就是 false 。
*/

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = l.size();
        vector<bool> ans;
        for (int i = 0; i < n; ++i) {
            int left = l[i], right = r[i];
            int minv = *min_element(nums.begin() + left, nums.begin() + right + 1);
            int maxv = *max_element(nums.begin() + left, nums.begin() + right + 1);

            if (minv == maxv) {
                ans.push_back(true);
                continue;
            }
            if ((maxv - minv) % (right - left) != 0) {
                ans.push_back(false);
                continue;
            }

            int d = (maxv - minv) / (right - left);
            bool flag = true;
            vector<int> seen(right - left + 1);
            for (int j = left; j <= right; ++j) {
                if ((nums[j] - minv) % d != 0) {
                    flag = false;
                    break;
                }
                int t = (nums[j] - minv) / d;
                if (seen[t]) {
                    flag = false;
                    break;
                }
                seen[t] = true;
            }
            ans.push_back(flag);
        }
        return ans;
    }
};
