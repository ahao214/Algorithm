#include<vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

/*
2441. 与对应负数同时存在的最大正整数

给你一个 不包含 任何零的整数数组 nums ，找出自身与对应的负数都在数组中存在的最大正整数 k 。

返回正整数 k ，如果不存在这样的整数，返回 -1 。
*/


class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int k = -1;
        for (auto x : nums) {
            auto p = find(nums.begin(), nums.end(), -x);
            if (p != nums.end()) {
                k = max(k, x);
            }
        }
        return k;
    }
};



class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int k = -1;
        unordered_set<int> s(nums.begin(), nums.end());
        for (auto x : nums) {
            if (s.count(-x)) {
                k = max(k, x);
            }
        }
        return k;
    }
};


class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0, j = nums.size() - 1; i < j; j--) {
            while (i < j && nums[i] < -nums[j]) {
                i++;
            }
            if (nums[i] == -nums[j]) {
                return nums[j];
            }
        }
        return -1;
    }
};