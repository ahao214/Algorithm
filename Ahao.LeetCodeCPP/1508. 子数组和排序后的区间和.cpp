#include<vector>
#include <algorithm>

using namespace std;



/*
1508. 子数组和排序后的区间和
给你一个数组 nums ，它包含 n 个正整数。你需要计算所有非空连续子数组的和，并将它们按升序排序，得到一个新的包含 n * (n + 1) / 2 个数字的数组。

请你返回在新数组中下标为 left 到 right （下标从 1 开始）的所有数字和（包括左右端点）。由于答案可能很大，请你将它对 10^9 + 7 取模后返回。
*/
typedef long long LL;
typedef pair<int, LL> PIL;
const int MOD = 1e9 + 7;
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int MODULO = 1000000007;
        int sumsLength = n * (n + 1) / 2;
        auto sums = vector <int>(sumsLength);
        int index = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                sums[index++] = sum;
            }
        }
        sort(sums.begin(), sums.end());
        int ans = 0;
        for (int i = left - 1; i < right; i++) {
            ans = (ans + sums[i]) % MODULO;
        }
        return ans;
    }
};