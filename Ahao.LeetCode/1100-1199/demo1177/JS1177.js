﻿var canMakePaliQueries = function (s, queries) {
    const n = s.length;
    const count = Array(n + 1).fill(0);
    for (let i = 0; i < n; i++) {
        count[i + 1] = count[i] ^ (1 << (s[i].charCodeAt(0) - 'a'.charCodeAt(0)));
    }
    const res = [];
    for (const query of queries) {
        const l = query[0], r = query[1], k = query[2];
        let bits = 0, x = count[r + 1] ^ count[l];
        while (x > 0) {
            x &= x - 1;
            bits++;
        }
        res.push(bits <= k * 2 + 1);
    }
    return res;
}
