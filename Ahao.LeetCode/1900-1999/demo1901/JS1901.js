﻿var maxElement = function (arr) {
    let i = 0;
    for (let j = 0; j < arr.length; j++) {
        if (arr[i] < arr[j]) {
            i = j;
        }
    }
    return i;
}

var findPeakGrid = function (mat) {
    const m = mat.length;
    let low = 0, high = m - 1;
    while (low <= high) {
        let i = Math.floor((low + high) / 2);
        let j = maxElement(mat[i]);
        if (i - 1 >= 0 && mat[i][j] < mat[i - 1][j]) {
            high = i - 1;
            continue;
        }
        if (i + 1 < m && mat[i][j] < mat[i + 1][j]) {
            low = i + 1;
            continue;
        }
        return [i, j];
    }
    return []; // impossible
};
