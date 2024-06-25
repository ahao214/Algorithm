function goodSubsetofBinaryMatrixTS(grid: number[][]): number[] {
    let ans: number[] = [];
    let mp: Map<number, number> = new Map();
    let m: number = grid.length;
    let n: number = grid[0].length;
    for (let j = 0; j < m; j++) {
        let st: number = 0;
        for (let i = 0; i < n; i++) {
            st |= (grid[j][i] << i);
        }
        mp.set(st, j);
    }

    if (mp.has(0)) {
        ans.push(mp.get(0)!);
        return ans;
    }

    for (let [x, i] of mp) {
        for (let [y, j] of mp) {
            if (!(x & y)) {
                return [Math.min(i, j), Math.max(i, j)];
            }
        }
    }

    return ans;
};
