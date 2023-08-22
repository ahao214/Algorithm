﻿var maxDistToClosest = function (seats) {
    let res = 0, l = 0;
    while (l < seats.length && seats[l] === 0) {
        l++;
    }
    res = Math.max(res, l);
    while (l < seats.length) {
        let r = l + 1;
        while (r < seats.length && seats[r] === 0) {
            r++;
        }
        if (r === seats.length) {
            res = Math.max(res, r - l - 1);
        } else {
            res = Math.max(res, parseInt((r - l) / 2));
        }
        l = r;
    }
    return res;
};
