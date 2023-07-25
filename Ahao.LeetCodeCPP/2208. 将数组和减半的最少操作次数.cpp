#include <numeric>
#include <queue>
#include<vector>

using namespace std;

/*
2208. 将数组和减半的最少操作次数

给你一个正整数数组 nums 。每一次操作中，你可以从 nums 中选择 任意 一个数并将它减小到 恰好 一半。（注意，在后续操作中你可以对减半过的数继续执行操作）

请你返回将 nums 数组和 至少 减少一半的 最少 操作数。
*/


class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq(nums.begin(), nums.end());
        int res = 0;
        double sum = accumulate(nums.begin(), nums.end(), 0.0), sum2 = 0.0;
        while (sum2 < sum / 2) {
            double x = pq.top();
            pq.pop();
            sum2 += x / 2;
            pq.push(x / 2);
            res++;
        }
        return res;
    }
};

