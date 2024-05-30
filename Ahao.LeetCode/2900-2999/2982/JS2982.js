﻿var maximumLength = function (s) {
    const n = s.length;
    const cnt = new Map();

    for (let i = 0, j = 0; i < n; i = j) {
        while (j < n && s[j] === s[i]) {
            j++;
        }
        const len = j - i;
        if (!cnt.has(s[i])) {
            cnt.set(s[i], []);
        }
        cnt.get(s[i]).push(len);
    }

    let res = -1;
    for (const vec of cnt.values()) {
        let lo = 1, hi = n - 2;
        while (lo <= hi) {
            const mid = (lo + hi) >> 1;
            let count = 0;
            for (const x of vec) {
                if (x >= mid) {
                    count += x - mid + 1;
                }
            }
            if (count >= 3) {
                res = Math.max(res, mid);
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
    }
    return res;
};
