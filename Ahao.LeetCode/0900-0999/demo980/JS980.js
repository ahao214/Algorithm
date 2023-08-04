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




const dirs = [[-1, 0], [1, 0], [0, -1], [0, 1]];
const memo = new Map();

var uniquePathsIII = function (grid) {
    memo.clear()
    const r = grid.length, c = grid[0].length;
    let si = 0, sj = 0, st = 0;
    for (let i = 0; i < r; i++) {
        for (let j = 0; j < c; j++) {
            if (grid[i][j] === 0 || grid[i][j] === 2) {
                st |= 1 << (i * c + j);
            } else if (grid[i][j] === 1) {
                si = i;
                sj = j;
            }
        }
    }
    return dp(grid, si, sj, st);
}

function dp(grid, i, j, st) {
    if (grid[i][j] === 2) {
        return st === 0 ? 1 : 0;
    }
    const r = grid.length, c = grid[0].length;
    const key = ((i * c + j) << (r * c)) + st;
    if (!memo.has(key)) {
        let res = 0;
        for (const dir of dirs) {
            const ni = i + dir[0],
                nj = j + dir[1];
            if (ni >= 0 && ni < r && nj >= 0 && nj < c && (st & (1 << (ni * c + nj))) > 0) {
                res += dp(grid, ni, nj, st ^ (1 << (ni * c + nj)));
            }
        }
        memo.set(key, res);
    }
    return memo.get(key);
}
