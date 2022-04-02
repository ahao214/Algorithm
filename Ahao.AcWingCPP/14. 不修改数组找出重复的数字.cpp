using namespace std;
#include<vector>
#include<unordered_set>

#pragma region 14. 不修改数组找出重复的数字

/*
给定一个长度为 n+1 的数组nums，数组中所有的数均在 1∼n 的范围内，其中 n≥1。

请找出数组中任意一个重复的数，但不能修改输入的数组。
*/

#pragma endregion


class Solution {
public:
    int duplicateInArray(vector<int>& nums) {
        unordered_set<int> nSet;
        int len = nums.size();
        int res = 0;
        for (int i = 0; i < len; i++)
        {
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