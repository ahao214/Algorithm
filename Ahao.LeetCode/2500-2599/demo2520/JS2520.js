﻿var countDigits = function (num) {
    let t = num;
    let res = 0;
    while (t) {
        if (num % (t % 10) == 0) {
            res += 1;
        }
        t = Math.floor(t / 10);
    }
    return res;
};
