﻿var numMovesStones = function(a, b, c) {
    let x = Math.min(Math.min(a, b), c);
    let z = Math.max(Math.max(a, b), c);
    let y = a + b + c - x - z;
    let res = [2, z - x - 2];
    if (z - y == 1 && y - x == 1) {
        res[0] = 0;
    } else if (z - y <= 2 || y - x <= 2) {
        res[0] = 1;
    }
    return res;
};
