﻿var reconstructMatrix = function (upper, lower, colsum) {
    let n = colsum.length;
    let sumVal = 0;
    let twoNum = 0;
    for (let i = 0; i < n; i++) {
        if (colsum[i] == 2) {
            twoNum++;
        }
        sumVal += colsum[i];
    }
    if (sumVal != upper + lower || Math.min(upper, lower) < twoNum) {
        return [];
    }
    upper -= twoNum;
    lower -= twoNum;
    let res = Array.from({ length: 2 }, () => new Array(n).fill(0));
    for (let i = 0; i < n; i++) {
        if (colsum[i] == 2) {
            res[0][i] = res[1][i] = 1;
        } else if (colsum[i] == 1) {
            if (upper > 0) {
                res[0][i] = 1;
                upper--;
            } else {
                res[1][i] = 1;
            }
        }
    }
    return res;
}
