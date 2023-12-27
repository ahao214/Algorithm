#include <numeric>
#include<vector>
#include <stack>

using namespace std;


/*
2735. 收集巧克力

给你一个长度为 n 、下标从 0 开始的整数数组 nums ，表示收集不同巧克力的成本。每个巧克力都对应一个不同的类型，最初，位于下标 i 的巧克力就对应第 i 个类型。

在一步操作中，你可以用成本 x 执行下述行为：

同时修改所有巧克力的类型，将巧克力的类型 ith 修改为类型 ((i + 1) mod n)th。
假设你可以执行任意次操作，请返回收集所有类型巧克力所需的最小成本。
*/





class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        int n = nums.size();
        vector<int> f(nums);
        long long ans = accumulate(f.begin(), f.end(), 0LL);
        for (int k = 1; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                f[i] = min(f[i], nums[(i + k) % n]);
            }
            ans = min(ans, static_cast<long long>(k) * x + accumulate(f.begin(), f.end(), 0LL));
        }
        return ans;
    }
};





class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        int n = nums.size();
        // 找出 nums 中最小的元素，并用其为首元素构造一个新的数组
        int min_idx = min_element(nums.begin(), nums.end()) - nums.begin();
        vector<int> tmp;
        for (int i = 0; i < n; ++i) {
            tmp.push_back(nums[(min_idx + i) % n]);
        }
        nums = move(tmp);

        vector<int> L(n), R(n);
        L[0] = n - 1;
        // 循环来看，右侧 nums[0] 是更小的元素，但不一定是第一个更小的元素，需要用单调栈计算得到
        for (int i = 0; i < n; ++i) {
            R[i] = n - i - 1;
        }
        stack<int> s;
        s.push(0);
        for (int i = 1; i < n; ++i) {
            while (!s.empty() && nums[i] < nums[s.top()]) {
                R[s.top()] = i - s.top() - 1;
                s.pop();
            }
            L[i] = i - s.top() - 1;
            s.push(i);
        }

        vector<long long> F(n);
        // 辅助函数，一次差分，将 F[l..r] 都增加 d
        auto diff_once = [&](int l, int r, long long d) {
            if (l > r) {
                return;
            }
            if (l < n) {
                F[l] += d;
            }
            if (r + 1 < n) {
                F[r + 1] -= d;
            }
            };
        // 辅助函数，二次差分，将 F[l..r] 增加 ki + b，i 是下标
        auto diff_twice = [&](int l, int r, long long k, long long b) {
            if (l > r) {
                return;
            }
            diff_once(l, l, k * l + b);
            diff_once(l + 1, r, k);
            diff_once(r + 1, r + 1, -(k * r + b));
            };

        // 进行操作需要的成本
        diff_twice(0, n - 1, x, 0);

        for (int i = 0; i < n; ++i) {
            int minv = min(L[i], R[i]);
            int maxv = max(L[i], R[i]);
            // 第一种情况，窗口数量 k+1，总和 nums[i] * k + nums[i]
            diff_twice(0, minv, nums[i], nums[i]);
            // 第二种情况，窗口数量 minv+1，总和 0 * k + nums[i] * (minv + 1)
            diff_twice(minv + 1, maxv, 0, static_cast<long long>(nums[i]) * (minv + 1));
            // 第三种情况，窗口数量 L[i]+R[i]-k+1，总和 -nums[i] * k + nums[i] * (L[i] + R[i] + 1)
            diff_twice(maxv + 1, L[i] + R[i], -nums[i], static_cast<long long>(nums[i]) * (L[i] + R[i] + 1));
        }

        // 计算两次前缀和
        for (int i = 0; i < 2; ++i) {
            vector<long long> G(n);
            partial_sum(F.begin(), F.end(), G.begin());
            F = move(G);
        }

        return *min_element(F.begin(), F.end());
    }
};
