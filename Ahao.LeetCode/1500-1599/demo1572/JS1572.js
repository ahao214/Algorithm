var diagonalSum = function (mat) {
    const n = mat.length;
    let sum = 0;
    for (let i = 0; i < n; ++i) {
        for (let j = 0; j < n; ++j) {
            if (i == j || i + j == n - 1) {
                sum += mat[i][j];
            }
        }
    }
    return sum;
};



var diagonalSum = function (mat) {
    const n = mat.length, mid = Math.floor(n / 2);
    let sum = 0;
    for (let i = 0; i < n; ++i) {
        sum += mat[i][i] + mat[i][n - 1 - i];
    }
    return sum - mat[mid][mid] * (n & 1);
};
