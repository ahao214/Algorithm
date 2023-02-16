﻿var largest1BorderedSquare = function (grid) {
    const m = grid.length, n = grid[0].length;
    const left = new Array(m + 1).fill(0).map(() => new Array(n + 1).fill(0));
    const up = new Array(m + 1).fill(0).map(() => new Array(n + 1).fill(0));
    let maxBorder = 0;
    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            if (grid[i - 1][j - 1] === 1) {
                left[i][j] = left[i][j - 1] + 1;
                up[i][j] = up[i - 1][j] + 1;
                let border = Math.min(left[i][j], up[i][j]);
                while (left[i - border + 1][j] < border || up[i][j - border + 1] < border) {
                    border--;
                }
                maxBorder = Math.max(maxBorder, border);
            }
        }
    }
    return maxBorder * maxBorder;
};
