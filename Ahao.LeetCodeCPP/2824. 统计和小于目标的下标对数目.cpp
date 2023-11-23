#include<vector>
#include <algorithm>

using namespace std;

/*
2824. 统计和小于目标的下标对数目

给你一个下标从 0 开始长度为 n 的整数数组 nums 和一个整数 target ，请你返回满足 0 <= i < j < n 且 nums[i] + nums[j] < target 的下标对 (i, j) 的数目。
*/

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] < target) {
                    res++;
                }
            }
        }
        return res;
    }
};


class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 1; i < nums.size(); i++) {
            int k = lower_bound(nums.begin(), nums.begin() + i, target - nums[i]) - nums.begin();
            res += k;
        }
        return res;
    }
};




class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0, j = nums.size() - 1; i < j; i++) {
            while (i < j && nums[i] + nums[j] >= target) {
                j--;
            }
            res += j - i;
        }
        return res;
    }
};
