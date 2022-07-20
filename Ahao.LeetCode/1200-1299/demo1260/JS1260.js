var shiftGrid = function (grid, k) {
    const m = grid.length, n = grid[0].length;
    const res = [];
    for (let i = 0; i < m; i++) {
        const row = [];
        for (let j = 0; j < n; j++) {
            row.push(0);
        }
        res.push(row);
    }

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            const index = (i * n + j + k) % (m * n);
            res[Math.floor(index / n)].splice(index % n, 1, grid[i][j]);
        }
    }

    return res;
};