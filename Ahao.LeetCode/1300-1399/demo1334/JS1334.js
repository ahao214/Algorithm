﻿var findTheCity = function (n, edges, distanceThreshold) {
    let ans = [Infinity, -1]
    const mp = new Array(n).fill(0).map(() => new Array(n).fill(Infinity));

    for (const [from, to, weight] of edges) {
        mp[from][to] = mp[to][from] = weight;
    }
    for (let k = 0; k < n; k++) {
        mp[k][k] = 0;
        for (let i = 0; i < n; i++) {
            for (let j = 0; j < n; j++) {
                mp[i][j] = Math.min(mp[i][j], mp[i][k] + mp[k][j]);
            }
        }
    }
    for (let i = 0; i < n; i++) {
        let cnt = 0;
        for (let j = 0; j < n; j++) {
            if (mp[i][j] <= distanceThreshold) {
                cnt++;
            }
        }
        if (cnt <= ans[0]) {
            ans = [cnt, i];
        }
    }
    return ans[1];
};




var findTheCity = function (n, edges, distanceThreshold) {
    let ans = [Infinity, -1];
    const dis = new Array(n).fill(0).map(() => new Array(n).fill(Infinity));
    const mp = new Array(n).fill(0).map(() => new Array(n).fill(Infinity));
    const vis = new Array(n).fill(0).map(() => new Array(n).fill(false));

    for (const [from, to, weight] of edges) {
        mp[from][to] = mp[to][from] = weight;
    }
    for (let i = 0; i < n; i++) {
        dis[i][i] = 0;
        for (let j = 0; j < n; j++) {
            let t = -1;
            for (let k = 0; k < n; ++k) {
                if (!vis[i][k] && (t == -1 || dis[i][k] < dis[i][t])) {
                    t = k;
                }
            }
            for (let k = 0; k < n; ++k) {
                dis[i][k] = Math.min(dis[i][k], dis[i][t] + mp[t][k]);
            }
            vis[i][t] = true;
        }
    }
    for (let i = 0; i < n; i++) {
        let cnt = 0;
        for (let j = 0; j < n; j++) {
            if (dis[i][j] <= distanceThreshold) {
                cnt++;
            }
        }
        if (cnt <= ans[0]) {
            ans = [cnt, i];
        }
    }
    return ans[1];
};

