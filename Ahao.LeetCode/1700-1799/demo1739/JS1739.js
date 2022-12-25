﻿var minimumBoxes = function (n) {
    let cur = 1, i = 1, j = 1;
    while (n > cur) {
        n -= cur;
        i++;
        cur += i;
    }
    cur = 1;
    while (n > cur) {
        n -= cur;
        j++;
        cur++;
    }
    return (i - 1) * i / 2 + j;
};



//二分查找
var minimumBoxes = function (n) {
    let i = 0, j = 0;
    let low = 1, high = Math.min(n, 100000);
    while (low < high) {
        const mid = (low + high) >> 1;
        const sum = mid * (mid + 1) * (mid + 2) / 6;
        if (sum >= n) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    i = low;
    n -= (i - 1) * i * (i + 1) / 6;
    low = 1;
    high = i;
    while (low < high) {
        const mid = (low + high) >> 1;
        const sum = mid * (mid + 1) / 2;
        if (sum >= n) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    j = low;
    return (i - 1) * i / 2 + j;
};
