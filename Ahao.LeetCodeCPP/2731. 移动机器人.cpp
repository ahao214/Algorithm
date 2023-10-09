#include<vector>
#include <string>
#include <algorithm>

using namespace std;


/*
2731. 移动机器人

有一些机器人分布在一条无限长的数轴上，他们初始坐标用一个下标从 0 开始的整数数组 nums 表示。当你给机器人下达命令时，它们以每秒钟一单位的速度开始移动。

给你一个字符串 s ，每个字符按顺序分别表示每个机器人移动的方向。'L' 表示机器人往左或者数轴的负方向移动，'R' 表示机器人往右或者数轴的正方向移动。

当两个机器人相撞时，它们开始沿着原本相反的方向移动。

请你返回指令重复执行 d 秒后，所有机器人之间两两距离之和。由于答案可能很大，请你将答案对 109 + 7 取余后返回。
*/

class Solution {
public:
    static constexpr int mod = 1e9 + 7;
    int sumDistance(vector<int>& nums, string s, int d) {
        int n = nums.size();
        vector<long long> pos(n);
        for (int i = 0; i < n; i++) {
            if (s[i] == 'L') {
                pos[i] = (long long)nums[i] - d;
            }
            else {
                pos[i] = (long long)nums[i] + d;
            }
        }
        sort(pos.begin(), pos.end());
        long long res = 0;
        for (int i = 1; i < n; i++) {
            res += 1ll * (pos[i] - pos[i - 1]) * i % mod * (n - i) % mod;
            res %= mod;
        }
        return res;
    }
};
