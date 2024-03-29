﻿var baseNeg2 = function(n) {
    if (n === 0) {
        return "0";
    }
    const bits = new Array(32).fill(0);
    for (let i = 0; i < 32 && n !== 0; i++) {
        if ((n & 1) !== 0) {
            bits[i]++;
            if ((i & 1) !== 0) {
                bits[i + 1]++;
            }
        }
        n >>= 1;
    }
    let carry = 0;
    for (let i = 0; i < 32; i++) {
        const val = carry + bits[i];
        bits[i] = val & 1;
        carry = (val - bits[i]) / (-2);
    }
    let pos = 31;
    let res = "";
    while (pos >= 0 && bits[pos] === 0) {
        pos--;
    }
    while (pos >= 0) {
        res += bits[pos];
        pos--;
    }
    return res;
};


var baseNeg2 = function (n) {
    if (n === 0 || n === 1) {
        return '' + n;
    }
    let res = '';
    while (n !== 0) {
        const remainder = n & 1;
        res += remainder;
        n -= remainder;
        n /= -2;
    }
    return res.split('').reverse().join('');
};




var baseNeg2 = function (n) {
    let val = 0x55555555 ^ (0x55555555 - n);
    if (val === 0) {
        return "0";
    }
    let res = "";
    while (val !== 0) {
        res += val & 1;
        val >>= 1;
    }
    return res.split('').reverse().join('');
};
