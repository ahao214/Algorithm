#include<vector>
#include <unordered_map>
#include <functional>

using namespace std;

/*
1815. 得到新鲜甜甜圈的最多组数

有一个甜甜圈商店，每批次都烤 batchSize 个甜甜圈。这个店铺有个规则，就是在烤一批新的甜甜圈时，之前 所有 甜甜圈都必须已经全部销售完毕。给你一个整数 batchSize 和一个整数数组 groups ，数组中的每个整数都代表一批前来购买甜甜圈的顾客，其中 groups[i] 表示这一批顾客的人数。每一位顾客都恰好只要一个甜甜圈。

当有一批顾客来到商店时，他们所有人都必须在下一批顾客来之前购买完甜甜圈。如果一批顾客中第一位顾客得到的甜甜圈不是上一组剩下的，那么这一组人都会很开心。

你可以随意安排每批顾客到来的顺序。请你返回在此前提下，最多 有多少组人会感到开心。
*/

class Solution {
public:
    int maxHappyGroups(int batchSize, vector<int>& groups) {
        vector<int> cnt(batchSize);
        for (int x : groups) {
            ++cnt[x % batchSize];
        }

        long long start = 0;
        for (int i = batchSize - 1; i >= 1; --i) {
            start = (start << kWidth) | cnt[i];
        }

        unordered_map<long long, int> memo;

        function<int(long long)> dfs = [&](long long mask) -> int {
            if (mask == 0) {
                return 0;
            }
            if (memo.count(mask)) {
                return memo[mask];
            }

            int total = 0;
            for (int i = 1; i < batchSize; ++i) {
                int amount = ((mask >> ((i - 1) * kWidth)) & kWidthMask);
                total += i * amount;
            }

            int best = 0;
            for (int i = 1; i < batchSize; ++i) {
                int amount = ((mask >> ((i - 1) * kWidth)) & kWidthMask);
                if (amount > 0) {
                    int result = dfs(mask - (1LL << ((i - 1) * kWidth)));
                    if ((total - i) % batchSize == 0) {
                        ++result;
                    }
                    best = max(best, result);
                }
            }

            return memo[mask] = best;
        };

        return dfs(start) + cnt[0];
    }

private:
    static constexpr int kWidth = 5;
    static constexpr int kWidthMask = (1 << kWidth) - 1;
};
