#include<vector>
#include <unordered_set>

using namespace std;

/*
764. 最大加号标志

中等

相关企业
在一个 n x n 的矩阵 grid 中，除了在数组 mines 中给出的元素为 0，其他每个元素都为 1。mines[i] = [xi, yi]表示 grid[xi][yi] == 0

返回  grid 中包含 1 的最大的 轴对齐 加号标志的阶数 。如果未找到加号标志，则返回 0 。

一个 k 阶由 1 组成的 “轴对称”加号标志 具有中心网格 grid[r][c] == 1 ，以及4个从中心向上、向下、向左、向右延伸，长度为 k-1，由 1 组成的臂。注意，只有加号标志的所有网格要求为 1 ，别的网格可能为 0 也可能为 1 。
*/

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> dp(n, vector<int>(n, n));
        unordered_set<int> banned;
        for (auto&& vec : mines) {
            banned.emplace(vec[0] * n + vec[1]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int count = 0;
            /* left */
            for (int j = 0; j < n; j++) {
                if (banned.count(i * n + j)) {
                    count = 0;
                }
                else {
                    count++;
                }
                dp[i][j] = min(dp[i][j], count);
            }
            count = 0;
            /* right */
            for (int j = n - 1; j >= 0; j--) {
                if (banned.count(i * n + j)) {
                    count = 0;
                }
                else {
                    count++;
                }
                dp[i][j] = min(dp[i][j], count);
            }
        }
        for (int i = 0; i < n; i++) {
            int count = 0;
            /* up */
            for (int j = 0; j < n; j++) {
                if (banned.count(j * n + i)) {
                    count = 0;
                }
                else {
                    count++;
                }
                dp[j][i] = min(dp[j][i], count);
            }
            count = 0;
            /* down */
            for (int j = n - 1; j >= 0; j--) {
                if (banned.count(j * n + i)) {
                    count = 0;
                }
                else {
                    count++;
                }
                dp[j][i] = min(dp[j][i], count);
                ans = max(ans, dp[j][i]);
            }
        }
        return ans;
    }
};
