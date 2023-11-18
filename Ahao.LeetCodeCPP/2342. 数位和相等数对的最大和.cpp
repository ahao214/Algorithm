#include<vector>

using namespace std;

/*
2342. 数位和相等数对的最大和

给你一个下标从 0 开始的数组 nums ，数组中的元素都是 正 整数。请你选出两个下标 i 和 j（i != j），且 nums[i] 的数位和 与  nums[j] 的数位和相等。

请你找出所有满足条件的下标 i 和 j ，找出并返回 nums[i] + nums[j] 可以得到的 最大值 。
*/


class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int ans = -1;
        int mx[82]{}; // 至多 9 个 9 相加
        for (int num : nums) {
            int s = 0; // num 的数位和
            for (int x = num; x; x /= 10) { // 枚举 num 的每个数位
                s += x % 10;
            }
            if (mx[s]) { // 说明左边也有数位和等于 s 的元素
                ans = max(ans, mx[s] + num); // 更新答案的最大值
            }
            mx[s] = max(mx[s], num); // 维护数位和等于 s 的最大元素
        }
        return ans;
    }
};
