﻿const dirs = [[0, -1], [0, 1], [1, 0], [-1, 0]];

var maximumMinutes = function (grid) {
    const m = grid.length;
    const n = grid[0].length;
    const INF = 1e9;
    const fireTime = new Array(m).fill(0).map(() => new Array(n).fill(INF));

    const bfs = function () {
        let q = [];
        for (let i = 0; i < m; i++) {
            for (let j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push([i, j])
                    fireTime[i][j] = 0
                }
            }
        }

        let time = 1;
        while (q.length > 0) {
            const tmp = q;
            q = [];
            for (const [cx, cy] of tmp) {
                for (const [i, j] of dirs) {
                    const nx = cx + i;
                    const ny = cy + j;
                    if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                        if (grid[nx][ny] == 2 || fireTime[nx][ny] != INF) {
                            continue;
                        }
                        q.push([nx, ny]);
                        fireTime[nx][ny] = time;
                    }
                }
            }
            time++;
        }
    };

    const check = function (stayTime) {
        visit = new Array(m).fill(0).map(() => new Array(n).fill(false));
        let q = [[0, 0, stayTime]]
        while (q.length > 0) {
            const tmp = q
            q = []
            for (const [cx, cy, time] of tmp) {
                for (const [i, j] of dirs) {
                    const nx = cx + i;
                    const ny = cy + j;
                    if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                        if (visit[nx][ny] || grid[nx][ny] == 2) {
                            continue;
                        }
                        /* 到达安全屋 */
                        if (nx == m - 1 && ny == n - 1) {
                            return fireTime[nx][ny] >= time + 1;
                        }
                        /* 火未到达当前位置 */
                        if (fireTime[nx][ny] > time + 1) {
                            q.push([nx, ny, time + 1]);
                            visit[nx][ny] = true;
                        }
                    }
                }
            }
        }
        return false;
    };

    /* 通过 bfs 求出每个格子着火的时间 */
    bfs();
    /* 二分查找找到最大停留时间 */
    let ans = -1;
    let low = 0, high = m * n;
    while (low <= high) {
        const mid = low + Math.floor((high - low) / 2);
        if (check(mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans >= m * n ? 1e9 : ans;
};
