﻿var modifiedGraphEdges = function (n, edges, source, destination, target) {
    let k = 0;
    for (const e of edges) {
        if (e[2] === -1) {
            ++k;
        }
    }

    if (dijkstra(source, destination, construct(n, edges, 0, target)) > target) {
        return [];
    }
    if (dijkstra(source, destination, construct(n, edges, k * (target - 1), target)) < target) {
        return [];
    }

    let left = 0, right = k * (target - 1), ans = 0;
    while (left <= right) {
        const mid = Math.floor((left + right) / 2);
        if (dijkstra(source, destination, construct(n, edges, mid, target)) >= target) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    for (const e of edges) {
        if (e[2] === -1) {
            if (ans >= target - 1) {
                e[2] = target;
                ans -= target - 1;
            } else {
                e[2] = 1 + ans;
                ans = 0;
            }
        }
    }

    return edges;
}

const dijkstra = (source, destination, adjMatrix) => {
    // 朴素的 dijkstra 算法
    // adjMatrix 是一个邻接矩阵
    const n = adjMatrix.length;
    const dist = new Array(n).fill(Number.MAX_VALUE);
    const used = new Array(n).fill(false);
    dist[source] = 0;

    for (let round = 0; round < n - 1; ++round) {
        let u = -1;
        for (let i = 0; i < n; ++i) {
            if (!used[i] && (u === -1 || dist[i] < dist[u])) {
                u = i;
            }
        }
        used[u] = true;
        for (let v = 0; v < n; ++v) {
            if (!used[v] && adjMatrix[u][v] != -1) {
                dist[v] = Math.min(dist[v], dist[u] + adjMatrix[u][v]);
            }
        }
    }

    return dist[destination];
}

const construct = (n, edges, idx, target) => {
    // 需要构造出第 idx 种不同的边权情况，返回一个邻接矩阵
    const adjMatrix = new Array(n).fill(0).map(() => new Array(n).fill(-1));
    for (const e of edges) {
        let u = e[0], v = e[1], w = e[2];
        if (w !== -1) {
            adjMatrix[u][v] = adjMatrix[v][u] = w;
        } else {
            if (idx >= target - 1) {
                adjMatrix[u][v] = adjMatrix[v][u] = target;
                idx -= (target - 1);
            } else {
                adjMatrix[u][v] = adjMatrix[v][u] = (1 + idx);
                idx = 0;
            }
        }
    }
    return adjMatrix;
};
