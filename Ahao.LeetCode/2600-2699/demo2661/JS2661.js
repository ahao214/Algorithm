﻿var firstCompleteIndex = function (arr, mat) {
    let n = mat.length, m = mat[0].length;
    let mp = new Map();
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            mp.set(mat[i][j], [i, j]);
        }
    }
    let rowCnt = new Array(n).fill(0);
    let colCnt = new Array(m).fill(0);
    for (let i = 0; i < arr.length; i++) {
        let v = mp.get(arr[i]);
        rowCnt[v[0]]++;
        if (rowCnt[v[0]] == m) {
            return i;
        }
        colCnt[v[1]]++;
        if (colCnt[v[1]] == n) {
            return i;
        }
    }
    return -1;
};
