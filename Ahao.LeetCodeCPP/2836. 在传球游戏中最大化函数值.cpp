#include<vector>

using namespace std;


/*
2836. 在传球游戏中最大化函数值

给你一个长度为 n 下标从 0 开始的整数数组 receiver 和一个整数 k 。

总共有 n 名玩家，玩家 编号 互不相同，且为 [0, n - 1] 中的整数。这些玩家玩一个传球游戏，receiver[i] 表示编号为 i 的玩家会传球给编号为 receiver[i] 的玩家。玩家可以传球给自己，也就是说 receiver[i] 可能等于 i 。

你需要从 n 名玩家中选择一名玩家作为游戏开始时唯一手中有球的玩家，球会被传 恰好 k 次。

如果选择编号为 x 的玩家作为开始玩家，定义函数 f(x) 表示从编号为 x 的玩家开始，k 次传球内所有接触过球玩家的编号之 和 ，如果有玩家多次触球，则 累加多次 。换句话说， f(x) = x + receiver[x] + receiver[receiver[x]] + ... + receiver(k)[x] 。

你的任务时选择开始玩家 x ，目的是 最大化 f(x) 。

请你返回函数的 最大值 。

注意：receiver 可能含有重复元素。
*/
using LL = long long;
class Solution {
public:
    long long getMaxFunctionValue(vector<int>& receiver, long long k)
    {
        int n = receiver.size();
        int M = ceil(log(k) / log(2));
        vector<vector<LL>>dp(n + 1, vector<LL>(M + 1));
        vector<vector<int>>pos(n + 1, vector<int>(M + 1));

        for (int i = 0; i < n; i++)
        {
            pos[i][0] = receiver[i];
            dp[i][0] = receiver[i];
        }

        for (int j = 1; j <= M; j++)
            for (int i = 0; i < n; i++)
            {
                pos[i][j] = pos[pos[i][j - 1]][j - 1];
                dp[i][j] = dp[i][j - 1] + dp[pos[i][j - 1]][j - 1];
            }

        vector<int>bits;
        for (int i = 0; i <= M; i++)
        {
            if ((k >> i) & 1)
                bits.push_back(i);
        }

        LL ret = 0;
        for (int i = 0; i < n; i++)
        {
            LL val = i;
            int cur = i;
            for (int j : bits)
            {
                val += dp[cur][j];
                cur = pos[cur][j];
            }
            ret = max(ret, val);
        }

        return ret;
    }
};


