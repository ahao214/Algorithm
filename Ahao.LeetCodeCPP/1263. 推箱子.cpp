#include<vector>
#include <queue>

using namespace std;

/*
1263. 推箱子

「推箱子」是一款风靡全球的益智小游戏，玩家需要将箱子推到仓库中的目标位置。

游戏地图用大小为 m x n 的网格 grid 表示，其中每个元素可以是墙、地板或者是箱子。

现在你将作为玩家参与游戏，按规则将箱子 'B' 移动到目标位置 'T' ：

玩家用字符 'S' 表示，只要他在地板上，就可以在网格中向上、下、左、右四个方向移动。
地板用字符 '.' 表示，意味着可以自由行走。
墙用字符 '#' 表示，意味着障碍物，不能通行。
箱子仅有一个，用字符 'B' 表示。相应地，网格上有一个目标位置 'T'。
玩家需要站在箱子旁边，然后沿着箱子的方向进行移动，此时箱子会被移动到相邻的地板单元格。记作一次「推动」。
玩家无法越过箱子。
返回将箱子推到目标位置的最小 推动 次数，如果无法做到，请返回 -1。
*/


class Solution {
public:
    int minPushBox(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int sx, sy, bx, by; // 玩家、箱子的初始位置
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                if (grid[x][y] == 'S') {
                    sx = x;
                    sy = y;
                }
                else if (grid[x][y] == 'B') {
                    bx = x;
                    by = y;
                }
            }
        }

        auto ok = [&](int x, int y) -> bool { // 不越界且不在墙上
            return x >= 0 && x < m&& y >= 0 && y < n&& grid[x][y] != '#';
        };
        vector<int> d = { 0, -1, 0, 1, 0 };

        vector<vector<int>> dp(m * n, vector<int>(m * n, INT_MAX));
        queue<pair<int, int>> q;
        dp[sx * n + sy][bx * n + by] = 0; // 初始状态的推动次数为 0
        q.push({ sx * n + sy, bx * n + by });
        while (!q.empty()) {
            queue<pair<int, int>> q1;
            while (!q.empty()) {
                auto [s1, b1] = q.front();
                q.pop();
                int sx1 = s1 / n, sy1 = s1 % n, bx1 = b1 / n, by1 = b1 % n;
                if (grid[bx1][by1] == 'T') { // 箱子已被推到目标处
                    return dp[s1][b1];
                }
                for (int i = 0; i < 4; i++) { // 玩家向四个方向移动到另一个状态
                    int sx2 = sx1 + d[i], sy2 = sy1 + d[i + 1], s2 = sx2 * n + sy2;
                    if (!ok(sx2, sy2)) { // 玩家位置不合法
                        continue;
                    }
                    if (bx1 == sx2 && by1 == sy2) { // 推动箱子
                        int bx2 = bx1 + d[i], by2 = by1 + d[i + 1], b2 = bx2 * n + by2;
                        if (!ok(bx2, by2) || dp[s2][b2] <= dp[s1][b1] + 1) { // 箱子位置不合法 或 状态已访问
                            continue;
                        }
                        dp[s2][b2] = dp[s1][b1] + 1;
                        q1.push({ s2, b2 });
                    }
                    else {
                        if (dp[s2][b1] <= dp[s1][b1]) { // 状态已访问
                            continue;
                        }
                        dp[s2][b1] = dp[s1][b1];
                        q.push({ s2, b1 });
                    }
                }
            }
            q.swap(q1);
        }
        return -1;
    }
};
