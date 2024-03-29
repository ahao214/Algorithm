#include<vector>
#include <algorithm>

using namespace std;

/*
891. 子序列宽度之和

困难

一个序列的 宽度 定义为该序列中最大元素和最小元素的差值。

给你一个整数数组 nums ，返回 nums 的所有非空 子序列 的 宽度之和 。由于答案可能非常大，请返回对 109 + 7 取余 后的结果。

子序列 定义为从一个数组里删除一些（或者不删除）元素，但不改变剩下元素的顺序得到的数组。例如，[3,6,2,7] 就是数组 [0,3,1,6,2,2,7] 的一个子序列。
*/

class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long res = 0, mod = 1e9 + 7;
        long long x = nums[0], y = 2;
        for (int j = 1; j < nums.size(); j++) {
            res = (res + nums[j] * (y - 1) - x) % mod;
            x = (x * 2 + nums[j]) % mod;
            y = y * 2 % mod;
        }
        return (res + mod) % mod;
    }
};




class Solution {
public:
    int mod = 1000000007;
    int sumSubseqWidths(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long res = 0, p = 1, sum = 0;
        for (auto x : nums)
        {
            res = (res + x * (p - 1) - sum) % mod;
            sum = (sum * 2 + x) % mod;
            p = p * 2 % mod;
        }
        return (res + mod) % mod;
    }
};