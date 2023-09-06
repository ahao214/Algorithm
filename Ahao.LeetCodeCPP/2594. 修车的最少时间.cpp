#include<vector>

using namespace std;


/*
2594. 修车的最少时间

给你一个整数数组 ranks ，表示一些机械工的 能力值 。ranks[i] 是第 i 位机械工的能力值。能力值为 r 的机械工可以在 r * n^2 分钟内修好 n 辆车。

同时给你一个整数 cars ，表示总共需要修理的汽车数目。

请你返回修理所有汽车 最少 需要多少时间。

注意：所有机械工可以同时修理汽车。

*/



class Solution {
public:
    using ll = long long;
    long long repairCars(vector<int>& ranks, int cars) {
        ll l = 1, r = 1ll * ranks[0] * cars * cars;
        auto check = [&](ll m) {
            ll cnt = 0;
            for (auto x : ranks) {
                cnt += sqrt(m / x);
            }
            return cnt >= cars;
        };
        while (l < r) {
            ll m = l + r >> 1;
            if (check(m)) {
                r = m;
            }
            else {
                l = m + 1;
            }
        }
        return l;
    }
};
