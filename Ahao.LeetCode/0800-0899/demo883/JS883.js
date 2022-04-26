var projectionArea = function (grid) {
    const n = grid.length;
    let xyArea = 0, yzArea = 0, zxArea = 0;
    for (let i = 0; i < n; i++) {
        let yzHeight = 0, zxHeight = 0;
        for (let j = 0; j < n; j++) {
            xyArea += grid[i][j] > 0 ? 1 : 0;
            yzHeight = Math.max(yzHeight, grid[i][j]);
            zxHeight = Math.max(zxHeight, grid[j][i]);
        }
        yzArea += yzHeight;
        zxArea += zxHeight;
    }
    return xyArea + yzArea + zxArea;
};
