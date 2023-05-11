﻿var queryString = function (s, n) {
    if (n === 1) {
        return [...s].indexOf('1') !== -1;
    }
    let k = 30;
    while ((1 << k) >= n) {
        --k;
    }
    if (s.length < (1 << (k - 1)) + k - 1 || s.length < n - (1 << k) + k + 1) {
        return false;
    }
    return help(s, k, 1 << (k - 1), (1 << k) - 1) && help(s, k + 1, 1 << k, n);
}

const help = (s, k, mi, ma) => {
    const set = new Set();
    let t = 0;
    for (let r = 0; r < s.length; ++r) {
        t = t * 2 + (s[r].charCodeAt() - '0'.charCodeAt());
        if (r >= k) {
            t -= (s[r - k].charCodeAt() - '0'.charCodeAt()) << k;
        }
        if (r >= k - 1 && t >= mi && t <= ma) {
            set.add(t);
        }
    }
    return set.size === ma - mi + 1;
};
