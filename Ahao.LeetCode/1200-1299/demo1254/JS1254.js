const dir = [[-1, 0], [1, 0], [0, -1], [0, 1]];
var closedIsland = function (grid) {
    const m = grid.length;
    const n = grid[0].length;
    let ans = 0;

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 0) {
                const qu = [];
                grid[i][j] = 1;
                let closed = true;

                qu.push([i, j]);
                while (qu.length) {
                    const arr = qu.shift();
                    let cx = arr[0], cy = arr[1];
                    if (cx === 0 || cy === 0 || cx === m - 1 || cy === n - 1) {
                        closed = false;
                    }
                    for (let d = 0; d < 4; d++) {
                        let nx = cx + dir[d][0];
                        let ny = cy + dir[d][1];
                        if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] === 0) {
                            grid[nx][ny] = 1;
                            qu.push([nx, ny]);
                        }
                    }
                }
                if (closed) {
                    ans++;
                }
            }
        }
    }
    return ans;
};




var closedIsland = function (grid) {
    let ans = 0;
    const m = grid.length;
    const n = grid[0].length;

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 0 && dfs(i, j, grid, m, n)) {
                ans++;
            }
        }
    }
    return ans;
}

const dfs = (x, y, grid, m, n) => {
    if (x < 0 || y < 0 || x >= m || y >= n) {
        return false;
    }
    if (grid[x][y] != 0) {
        return true;
    }
    grid[x][y] = -1;
    const ret1 = dfs(x - 1, y, grid, m, n);
    const ret2 = dfs(x + 1, y, grid, m, n);
    const ret3 = dfs(x, y - 1, grid, m, n);
    const ret4 = dfs(x, y + 1, grid, m, n);
    return ret1 && ret2 && ret3 && ret4;
};
