﻿var countEven = function (num) {
    let res = 0;
    for (let i = 1; i <= num; i++) {
        let x = i, sum = 0;
        while (x !== 0) {
            sum += x % 10;
            x = Math.floor(x / 10);
        }
        if (sum % 2 === 0) {
            res++;
        }
    }
    return res;
};
