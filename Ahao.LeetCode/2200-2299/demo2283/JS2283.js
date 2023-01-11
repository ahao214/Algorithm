﻿var digitCount = function (num) {
    const h = new Map();
    const n = num.length;
    for (let i = 0; i < n; i++) {
        const digit = num[i].charCodeAt() - '0'.charCodeAt();
        h.set(digit, (h.get(digit) || 0) + 1);
    }
    for (let i = 0; i < n; i++) {
        const v = num[i].charCodeAt() - '0'.charCodeAt();
        if ((h.get(i) || 0) !== v) {
            return false;
        }
    }
    return true;
};
