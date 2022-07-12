//方法一：直接模拟
var oddCells = function (m, n, indices) {
    let res = 0;
    const matrix = new Array(m).fill(0).map(() => new Array(n).fill(0));
    for (const index of indices) {
        for (let i = 0; i < n; i++) {
            matrix[index[0]][i]++;
        }
        for (let i = 0; i < m; i++) {
            matrix[i][index[1]]++;
        }
    }
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if ((matrix[i][j] & 1) !== 0) {
                res++;
            }
        }
    }
    return res;
};


//方法二：模拟空间优化
var oddCells = function (m, n, indices) {
    const rows = new Array(m).fill(0);
    const cols = new Array(n).fill(0);
    for (const index of indices) {
        rows[index[0]]++;
        cols[index[1]]++;
    }
    let res = 0;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (((rows[i] + cols[j]) & 1) !== 0) {
                res++;
            }
        }
    }
    return res;
};



//方法三：计数优化
var oddCells = function (m, n, indices) {
    const rows = new Array(m).fill(0);
    const cols = new Array(n).fill(0);
    for (const index of indices) {
        rows[index[0]]++;
        cols[index[1]]++;
    }
    let oddx = 0, oddy = 0;
    for (let i = 0; i < m; i++) {
        if ((rows[i] & 1) !== 0) {
            oddx++;
        }
    }
    for (let i = 0; i < n; i++) {
        if ((cols[i] & 1) !== 0) {
            oddy++;
        }
    }
    return oddx * (n - oddy) + (m - oddx) * oddy;
};

