﻿var subtractProductAndSum = function (n) {
    let m = 1, s = 0;
    while (n > 0) {
        let x = n % 10;
        n = Math.floor(n / 10);
        m *= x;
        s += x;
    }
    return m - s;
}
