#include<vector>
#include<string>
#include <queue>

using namespace std;

/*
2258. 逃离火灾

给你一个下标从 0 开始大小为 m x n 的二维整数数组 grid ，它表示一个网格图。每个格子为下面 3 个值之一：

0 表示草地。
1 表示着火的格子。
2 表示一座墙，你跟火都不能通过这个格子。
一开始你在最左上角的格子 (0, 0) ，你想要到达最右下角的安全屋格子 (m - 1, n - 1) 。每一分钟，你可以移动到 相邻 的草地格子。每次你移动 之后 ，着火的格子会扩散到所有不是墙的 相邻 格子。

请你返回你在初始位置可以停留的 最多 分钟数，且停留完这段时间后你还能安全到达安全屋。如果无法实现，请你返回 -1 。如果不管你在初始位置停留多久，你 总是 能到达安全屋，请你返回 109 。

注意，如果你到达安全屋后，火马上到了安全屋，这视为你能够安全到达安全屋。

如果两个格子有共同边，那么它们为 相邻 格子。
*/


class Solution {
public:
    constexpr static int dirs[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    constexpr static int INF = 1e9;
    int maximumMinutes(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> fireTime(m, vector<int>(n, INF));
        /* 通过 bfs 求出每个格子着火的时间 */
        bfs(grid, fireTime);
        /* 找到起点到终点的最短时间 */
        int arriveTime = getArriveTime(grid, fireTime, 0);
        /* 安全屋不可达 */
        if (arriveTime < 0) {
            return -1;
        }
        /* 火不会到达安全屋 */
        if (fireTime[m - 1][n - 1] == INF) {
            return 1e9;
        }
        int ans = fireTime[m - 1][n - 1] - arriveTime;
        return getArriveTime(grid, fireTime, ans) >= 0 ? ans : (ans - 1);
    }

    void bfs(vector<vector<int>>& grid, vector<vector<int>>& fireTime) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.emplace(i, j);
                    fireTime[i][j] = 0;
                }
            }
        }

        int time = 1;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto [cx, cy] = q.front();
                q.pop();
                for (int j = 0; j < 4; j++) {
                    int nx = cx + dirs[j][0];
                    int ny = cy + dirs[j][1];
                    if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                        if (grid[nx][ny] == 2 || fireTime[nx][ny] != INF) {
                            continue;
                        }
                        q.emplace(nx, ny);
                        fireTime[nx][ny] = time;
                    }
                }
            }
            time++;
        }
    }

    int getArriveTime(vector<vector<int>>& grid, vector<vector<int>>& fireTime, int stayTime) {
        int m = fireTime.size();
        int n = fireTime[0].size();
        queue<tuple<int, int, int>> q;
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        q.emplace(0, 0, stayTime);
        visit[0][0] = true;
        while (!q.empty()) {
            auto [cx, cy, time] = q.front();
            q.pop();
            for (int j = 0; j < 4; j++) {
                int nx = cx + dirs[j][0];
                int ny = cy + dirs[j][1];
                if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                    if (grid[nx][ny] == 2 || visit[nx][ny]) {
                        continue;
                    }
                    if (nx == m - 1 && ny == n - 1) {
                        return time + 1;
                    }
                    if (fireTime[nx][ny] > time + 1) {
                        visit[nx][ny] = true;
                        q.emplace(nx, ny, time + 1);
                    }
                }
            }
        }
        return -1;
    }
};
