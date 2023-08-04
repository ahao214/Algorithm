﻿const dirs = [[-1, 0], [1, 0], [0, -1], [0, 1]];

var uniquePathsIII = function (grid) {
    const r = grid.length, c = grid[0].length;
    let si = 0, sj = 0, n = 0;
    for (let i = 0; i < r; i++) {
        for (let j = 0; j < c; j++) {
            if (grid[i][j] === 0) {
                n++;
            } else if (grid[i][j] === 1) {
                n++;
                si = i;
                sj = j;
            }
        }
    }
    return dfs(grid, si, sj, n);
};

function dfs(grid, i, j, n) {
    if (grid[i][j] === 2) {
        return n === 0 ? 1 : 0;
    }
    const r = grid.length, c = grid[0].length, t = grid[i][j];
    grid[i][j] = -1;
    let res = 0;
    for (const dir of dirs) {
        const ni = i + dir[0], nj = j + dir[1];
        if (ni >= 0 && ni < r && nj >= 0 && nj < c && (grid[ni][nj] === 0 || grid[ni][nj] === 2)) {
            res += dfs(grid, ni, nj, n - 1);
        }
    }
    grid[i][j] = t;
    return res;
}
