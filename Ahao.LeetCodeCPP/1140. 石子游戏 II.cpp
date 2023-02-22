#include<vector>
#include <numeric>

using namespace std;


/*
1140. 石子游戏 II

爱丽丝和鲍勃继续他们的石子游戏。许多堆石子 排成一行，每堆都有正整数颗石子 piles[i]。游戏以谁手中的石子最多来决出胜负。

爱丽丝和鲍勃轮流进行，爱丽丝先开始。最初，M = 1。

在每个玩家的回合中，该玩家可以拿走剩下的 前 X 堆的所有石子，其中 1 <= X <= 2M。然后，令 M = max(M, X)。

游戏一直持续到所有石子都被拿走。

假设爱丽丝和鲍勃都发挥出最佳水平，返回爱丽丝可以得到的最大数量的石头。
*/

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MIN));
        for (int i = n; i >= 0; i--) {
            for (int m = 1; m <= n; m++) {
                if (i == n) {
                    dp[i][m] = 0;
                }
                else {
                    int sum = 0;
                    for (int x = 1; x <= 2 * m; x++) {
                        if (i + x > n) {
                            break;
                        }
                        sum += piles[i + x - 1];
                        dp[i][m] = max(dp[i][m], sum - dp[i + x][min(n, max(m, x))]);
                    }
                }
            }
        }
        return (dp[0][1] + accumulate(piles.begin(), piles.end(), 0)) / 2;
    }
};
