var countGoodRectangles = function (rectangles) {
    let res = 0,
        maxLen = 0;
    for (const rec of rectangles) {
        const i = rec[0],
            j = rec[1];
        const k = Math.max(i, j);
        if (k == maxLen) {
            ++res;
        } else if (k > maxLen) {
            res = 1;
            maxLen = k;
        }
    }
    return res;
};