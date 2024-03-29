﻿var findCenter = function (edges) {
    const n = edges.length + 1;
    const degrees = new Array(n + 1).fill(0);
    for (const edge of edges) {
        degrees[edge[0]]++;
        degrees[edge[1]]++;
    }
    for (let i = 1; i <= n; i++) {
        if (degrees[i] === n - 1) {
            return i;
        }
    }
    return 0;
};