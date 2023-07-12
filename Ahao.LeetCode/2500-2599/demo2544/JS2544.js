﻿var alternateDigitSum = function(n) {
    let res = 0, sign = 1;
    while (n > 0) {
        res += n % 10 * sign;
        sign = -sign;
        n = Math.floor(n / 10);
    }
    return -sign * res;
};
