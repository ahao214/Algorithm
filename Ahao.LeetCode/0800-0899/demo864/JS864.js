﻿const dirs = [[-1, 0], [1, 0], [0, -1], [0, 1]];
var shortestPathAllKeys = function (grid) {
    const m = grid.length, n = grid[0].length;
    let sx = 0, sy = 0;
    const keyToIndex = new Map();
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (grid[i][j] === '@') {
                sx = i;
                sy = j;
            } else if ('a' <= grid[i][j] && grid[i][j] <= 'z') {
                if (!keyToIndex.has(grid[i][j])) {
                    const idx = keyToIndex.size;
                    keyToIndex.set(grid[i][j], idx);
                }
            }
        }
    }

    const queue = [];
    const dist = new Array(m).fill(0).map(() => new Array(n).fill(0).map(() => new Array(1 << keyToIndex.size).fill(-1)));
    queue.push([sx, sy, 0]);
    dist[sx][sy][0] = 0;
    while (queue.length) {
        const arr = queue.shift();
        let x = arr[0], y = arr[1], mask = arr[2];
        for (let i = 0; i < 4; ++i) {
            let nx = x + dirs[i][0];
            let ny = y + dirs[i][1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] !== '#') {
                if (grid[nx][ny] === '.' || grid[nx][ny] === '@') {
                    if (dist[nx][ny][mask] === -1) {
                        dist[nx][ny][mask] = dist[x][y][mask] + 1;
                        queue.push([nx, ny, mask]);
                    }
                } else if ('a' <= grid[nx][ny] && grid[nx][ny] <= 'z') {
                    const idx = keyToIndex.get(grid[nx][ny]);
                    if (dist[nx][ny][mask | (1 << idx)] === -1) {
                        dist[nx][ny][mask | (1 << idx)] = dist[x][y][mask] + 1;
                        if ((mask | (1 << idx)) === (1 << keyToIndex.size) - 1) {
                            return dist[nx][ny][mask | (1 << idx)];
                        }
                        queue.push([nx, ny, mask | (1 << idx)]);
                    }
                } else {
                    const idx = keyToIndex.get(grid[nx][ny].toLowerCase());
                    if ((mask & (1 << idx)) !== 0 && dist[nx][ny][mask] === -1) {
                        dist[nx][ny][mask] = dist[x][y][mask] + 1;
                        queue.push([nx, ny, mask]);
                    }
                }
            }
        }
    }
    return -1;
};
