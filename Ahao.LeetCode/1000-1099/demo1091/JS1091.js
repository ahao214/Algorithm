﻿var shortestPathBinaryMatrix = function(grid) {
    if (grid[0][0] === 1) {
        return -1;
    }
    const n = grid.length;
    const dist = new Array(n).fill(undefined).map(() => new Array(n).fill(Infinity));
    dist[0][0] = 1;
    const queue = [[0, 0]];
    while (queue.length > 0) {
        const [x, y] = queue.shift();
        for (let dx = -1; dx <= 1; dx++) {
            for (let dy = -1; dy <= 1; dy++) {
                if (x == n - 1 && y == n - 1) {
                    return dist[x][y];
                }
                if (x + dx < 0 || x + dx >= n || y + dy < 0 || y + dy >= n) { // 越界
                    continue;
                }
                if (grid[x + dx][y + dy] > 0 || dist[x + dx][y + dy] <= dist[x][y] + 1) { // 单元格值不为 0 或已被访问
                    continue;
                }
                dist[x + dx][y + dy] = dist[x][y] + 1;
                queue.push([x + dx, y + dy]);
            }
        }
    }
    return -1;
}