#include<vector>
#include <algorithm>

using namespace std;


/*
2357. 使数组中所有元素都等于零

给你一个非负整数数组 nums 。在一步操作中，你必须：

选出一个正整数 x ，x 需要小于或等于 nums 中 最小 的 非零 元素。
nums 中的每个正整数都减去 x。
返回使 nums 中所有元素都等于 0 需要的 最少 操作数。
*/



class Solution {
public:
    void subtract(vector<int>& nums, int x, int startIndex) {
        int length = nums.size();
        for (int i = startIndex; i < length; i++) {
            nums[i] -= x;
        }
    }

    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        int length = nums.size();
        for (int i = 0; i < length; i++) {
            if (nums[i] > 0) {
                subtract(nums, nums[i], i);
                ans++;
            }
        }
        return ans;
    }
};
