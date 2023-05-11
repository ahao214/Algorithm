#include<vector>

using namespace std;

/*
1330. 翻转子数组得到最大的数组值

给你一个整数数组 nums 。「数组值」定义为所有满足 0 <= i < nums.length-1 的 |nums[i]-nums[i+1]| 的和。

你可以选择给定数组的任意子数组，并将该子数组翻转。但你只能执行这个操作 一次 。

请你找到可行的最大 数组值 。
*/


class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int value = 0, n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            value += abs(nums[i] - nums[i + 1]);
        }
        int mx1 = 0;
        for (int i = 1; i < n - 1; i++) {
            mx1 = max(mx1, abs(nums[0] - nums[i + 1]) - abs(nums[i] - nums[i + 1]));
            mx1 = max(mx1, abs(nums[n - 1] - nums[i - 1]) - abs(nums[i] - nums[i - 1]));
        }
        int mx2 = INT_MIN, mn2 = INT_MAX;
        for (int i = 0; i < n - 1; i++) {
            int x = nums[i], y = nums[i + 1];
            mx2 = max(mx2, min(x, y));
            mn2 = min(mn2, max(x, y));
        }
        return value + max(mx1, 2 * (mx2 - mn2));
    }
};
