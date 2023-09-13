﻿var checkValidGrid = function (grid) {
    if (grid[0][0] != 0) {
        return false;
    }
    const n = grid.length;
    let indices = Array(n * n).fill().map(() => Array(2));
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            indices[grid[i][j]][0] = i;
            indices[grid[i][j]][1] = j;
        }
    }
    for (let i = 1; i < n * n; i++) {
        let dx = Math.abs(indices[i][0] - indices[i - 1][0]);
        let dy = Math.abs(indices[i][1] - indices[i - 1][1]);
        if (dx * dy != 2) {
            return false;
        }
    }
    return true;
};
