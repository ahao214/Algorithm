﻿var collectTheCoins = function (coins, edges) {
    n = coins.length
    g = new Array(n).fill(0).map(() => new Array());
    degree = new Array(n).fill(0);
    for (const edge of edges) {
        let x = edge[0], y = edge[1];
        g[x].push(y);
        g[y].push(x);
        degree[x]++;
        degree[y]++;
    }

    let rest = n;
    let q = [];
    // 删除树中所有无金币的叶子节点，直到树中所有的叶子节点都是含有金币的 
    for (let i = 0; i < n; i++) {
        if (degree[i] == 1 && coins[i] == 0) {
            q.push(i);
        }
    }
    while (q.length > 0) {
        const u = q.shift();
        degree[u]--;
        rest--;
        for (const v of g[u]) {
            degree[v]--;
            if (degree[v] == 1 && coins[v] == 0) {
                q.push(v)
            }
        }
    }

    // 删除树中所有的叶子节点, 连续删除2次
    for (let j = 0; j < 2; j++) {
        let q = [];
        for (let i = 0; i < n; i++) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }
        while (q.length > 0) {
            u = q.shift();
            degree[u]--;
            rest--;
            for (const v of g[u]) {
                degree[v]--;
            }
        }
    }

    return rest == 0 ? 0 : (rest - 1) * 2;
};
