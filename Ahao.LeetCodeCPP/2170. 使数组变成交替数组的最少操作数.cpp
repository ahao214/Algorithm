#include<vector>

using namespace std;


/*
2170. 使数组变成交替数组的最少操作数
给你一个下标从 0 开始的数组 nums ，该数组由 n 个正整数组成。

如果满足下述条件，则数组 nums 是一个 交替数组 ：

nums[i - 2] == nums[i] ，其中 2 <= i <= n - 1 。
nums[i - 1] != nums[i] ，其中 1 <= i <= n - 1 。
在一步 操作 中，你可以选择下标 i 并将 nums[i] 更改 为 任一 正整数。

返回使数组变成交替数组的 最少操作数 。
*/
class Solution {

    int a[100001], b[100002], c[100002], d[100002];
public:
    int minimumOperations(vector<int>& nums) {
        memset(a, 0, sizeof(a));
        int n = nums.size(), m = 0;
        for (int i = 0; i < n; i += 2)
            ++a[nums[i]], ++m;
        int m1 = 0;
        memset(b, 0, sizeof(a));
        for (int i = 1; i < n; i += 2)
            ++b[nums[i]], ++m1;
        for (int i = 1; i <= 100000; i++)
            c[i] = max(c[i - 1], b[i]);
        for (int i = 100000; i; --i)
            d[i] = max(d[i + 1], b[i]);
        int ans = 1 << 30;
        for (int i = 1; i <= 100000; i++)
            ans = min(ans, m - a[i] + m1 - max(c[i - 1], d[i + 1]));
        return ans;
    }
};
