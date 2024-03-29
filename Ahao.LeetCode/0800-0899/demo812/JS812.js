﻿//方法一：枚举
var largestTriangleArea = function (points) {
    const n = points.length;
    let ret = 0.0;
    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            for (let k = j + 1; k < n; k++) {
                ret = Math.max(ret, triangleArea(points[i][0], points[i][1], points[j][0], points[j][1], points[k][0], points[k][1]));
            }
        }
    }
    return ret;
};

const triangleArea = (x1, y1, x2, y2, x3, y3) => {
    return 0.5 * Math.abs(x1 * y2 + x2 * y3 + x3 * y1 - x1 * y3 - x2 * y1 - x3 * y2);
}


//方法二：凸包
var largestTriangleArea = function (points) {
    const convexHull = getConvexHull(points);
    const n = convexHull.length;
    let ret = 0.0;
    for (let i = 0; i < n; i++) {
        for (let j = i + 1, k = i + 2; j + 1 < n; j++) {
            while (k + 1 < n) {
                const curArea = triangleArea(convexHull[i][0], convexHull[i][1], convexHull[j][0], convexHull[j][1], convexHull[k][0], convexHull[k][1]);
                const nextArea = triangleArea(convexHull[i][0], convexHull[i][1], convexHull[j][0], convexHull[j][1], convexHull[k + 1][0], convexHull[k + 1][1]);
                if (curArea >= nextArea) {
                    break;
                }
                k++;
            }
            const area = triangleArea(convexHull[i][0], convexHull[i][1], convexHull[j][0], convexHull[j][1], convexHull[k][0], convexHull[k][1]);
            ret = Math.max(ret, area);
        }
    }
    return ret;
}

const getConvexHull = (points) => {
    const n = points.length;
    if (n < 4) {
        return points;
    }
    /* 按照 x 大小进行排序，如果 x 相同，则按照 y 的大小进行排序 */
    points.sort((a, b) => {
        if (a[0] === b[0]) {
            return a[1] - b[1];
        }
        return a[0] - b[0];
    });
    const hull = [];
    /* 求出凸包的下半部分 */
    for (let i = 0; i < n; i++) {
        while (hull.length > 1 && cross(hull[hull.length - 2], hull[hull.length - 1], points[i]) <= 0) {
            hull.pop();
        }
        hull.push(points[i]);
    }
    let m = hull.length;
    /* 求出凸包的上半部分 */
    for (let i = n - 2; i >= 0; i--) {
        while (hull.length > m && cross(hull[hull.length - 2], hull[hull.length - 1], points[i]) <= 0) {
            hull.pop();
        }
        hull.push(points[i]);
    }
    /* hull[0] 同时参与凸包的上半部分检测，因此需去掉重复的 hull[0] */
    hull.pop();
    m = hull.length;
    const hullArr = new Array(m).fill(0);
    for (let i = 0; i < m; i++) {
        hullArr[i] = hull[i];
    }
    return hullArr;
}

const triangleArea = (x1, y1, x2, y2, x3, y3) => {
    return 0.5 * Math.abs(x1 * y2 + x2 * y3 + x3 * y1 - x1 * y3 - x2 * y1 - x3 * y2);
}

const cross = (p, q, r) => {
    return (q[0] - p[0]) * (r[1] - q[1]) - (q[1] - p[1]) * (r[0] - q[0]);
};
