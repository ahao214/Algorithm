﻿var countServers = function (grid) {
    const m = grid.length, n = grid[0].length;
    const rows = new Map();
    const cols = new Map();
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (grid[i][j] == 1) {
                rows.set(i, (rows.get(i) || 0) + 1);
                cols.set(j, (cols.get(j) || 0) + 1);
            }
        }
    }
    let ans = 0;
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if (grid[i][j] == 1 && ((rows.get(i) || 0) > 1 || (cols.get(j) || 0) > 1)) {
                ++ans;
            }
        }
    }
    return ans;
};
