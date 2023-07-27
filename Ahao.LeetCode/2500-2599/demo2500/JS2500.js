﻿var deleteGreatestValue = function (grid) {
    const m = grid.length, n = grid[0].length;
    for (let i = 0; i < m; i++) {
        grid[i].sort((a, b) => a - b);
    }
    let res = 0;
    for (let j = 0; j < n; j++) {
        let mx = 0;
        for (let i = 0; i < m; i++) {
            mx = Math.max(mx, grid[i][j]);
        }
        res += mx;
    }
    return res;
};
