﻿var possibleToStamp = function (grid, stampHeight, stampWidth) {
    const m = grid.length, n = grid[0].length;
    const psum = new Array(m + 2).fill(0).map(() => new Array(n + 2).fill(0));
    const diff = new Array(m + 2).fill(0).map(() => new Array(n + 2).fill(0));
    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            psum[i][j] = psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1] + grid[i - 1][j - 1];
        }
    }

    for (let i = 1; i + stampHeight - 1 <= m; i++) {
        for (let j = 1; j + stampWidth - 1 <= n; j++) {
            const x = i + stampHeight - 1;
            const y = j + stampWidth - 1;
            if (psum[x][y] - psum[x][j - 1] - psum[i - 1][y] + psum[i - 1][j - 1] == 0) {
                diff[i][j]++;
                diff[i][y + 1]--;
                diff[x + 1][j]--;
                diff[x + 1][y + 1]++;
            }
        }
    }
    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];
            if (diff[i][j] == 0 && grid[i - 1][j - 1] == 0) {
                return false;
            }
        }
    }
    return true;
};
