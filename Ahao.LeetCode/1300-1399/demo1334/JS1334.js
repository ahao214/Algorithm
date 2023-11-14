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
