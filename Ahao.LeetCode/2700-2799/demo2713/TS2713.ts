﻿function maxIncreasingCellsTS(mat: number[][]): number {
    const m: number = mat.length;
    const n: number = mat[0].length;
    const mp: Map<number, [number, number][]> = new Map();
    const row: number[] = new Array(m).fill(0);
    const col: number[] = new Array(n).fill(0);

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (!mp.has(mat[i][j])) {
                mp.set(mat[i][j], []);
            }
            mp.get(mat[i][j])!.push([i, j]);
        }
    }
    const sortedMap: Map<number, [number, number][]> = new Map([...mp.entries()].sort((a, b) => a[0] - b[0]));
    for (const [_, pos] of sortedMap) {
        const res: number[] = pos.map(([i, j]) => Math.max(row[i], col[j]) + 1); // 存放相同数值的答案，便于后续更新 row 和 col
        for (let k = 0; k < pos.length; k++) {
            const [i, j] = pos[k];
            const d = res[k];
            row[i] = Math.max(row[i], d);
            col[j] = Math.max(col[j], d);
        }
    }
    return Math.max(...row);
};
