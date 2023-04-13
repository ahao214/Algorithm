#include<vector>
#include <unordered_map>

using namespace std;

/*
2404. 出现最频繁的偶数元素

给你一个整数数组 nums ，返回出现最频繁的偶数元素。

如果存在多个满足条件的元素，只需要返回 最小 的一个。如果不存在这样的元素，返回 -1 。
*/

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> count;
        for (auto x : nums) {
            if (x % 2 == 0) {
                count[x]++;
            }
        }
        int res = -1, ct = 0;
        for (auto& p : count) {
            if (res == -1 || p.second > ct || p.second == ct && res > p.first) {
                res = p.first;
                ct = p.second;
            }
        }
        return res;
    }
};
