﻿var frogPosition = function (n, edges, t, target) {
    let G = [];
    for (let i = 0; i <= n; i++) {
        G.push([]);
    }
    for (let e of edges) {
        G[e[0]].push(e[1]);
        G[e[1]].push(e[0]);
    }
    let seen = new Array(n).fill(false);
    return dfs(G, seen, 1, t, target);
}

function dfs(G, seen, i, t, target) {
    let nxt = i == 1 ? G[i].length : G[i].length - 1;
    if (t == 0 || nxt == 0) {
        return i == target ? 1.0 : 0.0;
    }
    seen[i] = true;
    let ans = 0.0;
    for (let j of G[i]) {
        if (!seen[j]) {
            ans += dfs(G, seen, j, t - 1, target);
        }
    }
    return ans / nxt;
}
