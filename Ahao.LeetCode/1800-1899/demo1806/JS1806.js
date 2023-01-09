﻿var reinitializePermutation = function (n) {
    let perm = new Array(n).fill(0).map((_, i) => i);
    const target = new Array(n).fill(0).map((_, i) => i);
    let step = 0;
    while (true) {
        const arr = new Array(n).fill(0);
        for (let i = 0; i < n; i++) {
            if ((i & 1) !== 0) {
                arr[i] = perm[Math.floor(n / 2) + Math.floor((i - 1) / 2)];
            } else {
                arr[i] = perm[Math.floor(i / 2)];
            }
        }
        perm = arr;
        step++;
        if (perm.toString() === target.toString()) {
            break;
        }
    }
    return step;
};
