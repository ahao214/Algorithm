#include<vector>
#include <unordered_map>

using namespace std;

/*
2032. 至少在两个数组中出现的值
给你三个整数数组 nums1、nums2 和 nums3 ，请你构造并返回一个 元素各不相同的 数组，且由 至少 在 两个 数组中出现的所有值组成。数组中的元素可以按 任意 顺序排列。
*/

class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_map<int, int> mp;
        for (auto& i : nums1) {
            mp[i] = 1;
        }
        for (auto& i : nums2) {
            mp[i] |= 2;
        }
        for (auto& i : nums3) {
            mp[i] |= 4;
        }
        vector<int> res;
        for (auto& [k, v] : mp) {
            if (v & (v - 1)) {
                res.push_back(k);
            }
        }
        return res;
    }
};
