using namespace std;
#include<string>;
#include<vector>;
#include <unordered_set>

/*
13. 找出数组中重复的数字

给定一个长度为 n 的整数数组 nums，数组中所有的数字都在 0∼n−1 的范围内。

数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。

请找出数组中任意一个重复的数字。

注意：如果某些数字不在 0∼n−1 的范围内，或数组中不包含重复数字，则返回 -1；

数据范围
0≤n≤1000
样例
给定 nums = [2, 3, 5, 4, 3, 2, 6, 7]。

返回 2 或 3。
*/
class Solution {
public:
    int duplicateInArray(vector<int>& nums) {
        int len = nums.size();
        for (auto& n : nums) {
            if (n < 0 || n >= len)
            {
                return -1;
            }
        }

        unordered_set<int> nSet;
        int res = -1;
        for (int i = 0; i < len; i++) {
            if (nSet.count(nums[i])) {
                res = nums[i];
                break;
            }
            else {
                nSet.insert(nums[i]);
            }
        }
        return res;
    }
};