﻿var maxWidthOfVerticalArea = function (points) {
    points.sort((a, b) => a[0] - b[0]);
    let mx = 0;
    for (let i = 1; i < points.length; i++) {
        mx = Math.max(points[i][0] - points[i - 1][0], mx);
    }
    return mx;
};
