function distance(ux, uy, vx, vy) {
    return (ux - vx) ** 2 + (uy - vy) ** 2
}

var checkOverlap = function (radius, xCenter, yCenter, x1, y1, x2, y2) {
    /* 圆心在矩形内部 */
    if (x1 <= xCenter && xCenter <= x2 && y1 <= yCenter && yCenter <= y2) {
        return true;
    }
    /* 圆心在矩形上部 */
    if (x1 <= xCenter && xCenter <= x2 && y2 <= yCenter && yCenter <= y2 + radius) {
        return true;
    }
    /* 圆心在矩形下部 */
    if (x1 <= xCenter && xCenter <= x2 && y1 - radius <= yCenter && yCenter <= y1) {
        return true;
    }
    /* 圆心在矩形左部 */
    if (x1 - radius <= xCenter && xCenter <= x1 && y1 <= yCenter && yCenter <= y2) {
        return true;
    }
    /* 圆心在矩形右部 */
    if (x2 <= xCenter && xCenter <= x2 + radius && y1 <= yCenter && yCenter <= y2) {
        return true;
    }
    /* 矩形左上角 */
    if (distance(xCenter, yCenter, x1, y2) <= radius * radius) {
        return true;
    }
    /* 矩形左下角 */
    if (distance(xCenter, yCenter, x1, y1) <= radius * radius) {
        return true;
    }
    /* 矩形右上角 */
    if (distance(xCenter, yCenter, x2, y2) <= radius * radius) {
        return true;
    }
    /* 矩形右下角 */
    if (distance(xCenter, yCenter, x1, y2) <= radius * radius) {
        return true;
    }
    /* 无交点 */
    return false;
};



var checkOverlap = function (radius, xCenter, yCenter, x1, y1, x2, y2) {
    dist = 0;
    if (xCenter < x1 || xCenter > x2) {
        dist += Math.min(Math.pow(x1 - xCenter, 2), Math.pow(x2 - xCenter, 2));
    }
    if (yCenter < y1 || yCenter > y2) {
        dist += Math.min(Math.pow(y1 - yCenter, 2), Math.pow(y2 - yCenter, 2));
    }
    return dist <= radius ** 2;
}
