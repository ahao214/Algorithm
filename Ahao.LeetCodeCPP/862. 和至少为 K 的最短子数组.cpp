#include<vector>
#include <deque>

using namespace std;

/*
862. 和至少为 K 的最短子数组

给你一个整数数组 nums 和一个整数 k ，找出 nums 中和至少为 k 的 最短非空子数组 ，并返回该子数组的长度。如果不存在这样的 子数组 ，返回 -1 。

子数组 是数组中 连续 的一部分。
*/

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long> preSumArr(n + 1);
        for (int i = 0; i < n; i++) {
            preSumArr[i + 1] = preSumArr[i] + nums[i];
        }
        int res = n + 1;
        deque<int> qu;
        for (int i = 0; i <= n; i++) {
            long curSum = preSumArr[i];
            while (!qu.empty() && curSum - preSumArr[qu.front()] >= k) {
                res = min(res, i - qu.front());
                qu.pop_front();
            }
            while (!qu.empty() && preSumArr[qu.back()] >= curSum) {
                qu.pop_back();
            }
            qu.push_back(i);
        }
        return res < n + 1 ? res : -1;
    }
};
