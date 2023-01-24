﻿var countPoints = function (points, queries) {
    const m = points.length, n = queries.length;
    const ans = new Array(n).fill(0);
    for (let i = 0; i < n; ++i) {
        let cx = queries[i][0], cy = queries[i][1], cr = queries[i][2];
        for (let j = 0; j < m; ++j) {
            let px = points[j][0], py = points[j][1];
            if ((cx - px) * (cx - px) + (cy - py) * (cy - py) <= cr * cr) {
                ++ans[i];
            }
        }
    }
    return ans;
};
