﻿var pivotInteger = function (n) {
    let t = (n * n + n) / 2;
    let x = parseInt(Math.sqrt(t));
    if (x * x === t) {
        return x;
    }
    return -1;
};
