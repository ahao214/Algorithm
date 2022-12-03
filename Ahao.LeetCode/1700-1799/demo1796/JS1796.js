﻿var secondHighest = function (s) {
    let first = -1, second = -1;
    for (let i = 0; i < s.length; i++) {
        const c = s[i];
        if ('0' <= c && c <= '9') {
            const num = c.charCodeAt() - '0'.charCodeAt();
            if (num > first) {
                second = first;
                first = num;
            } else if (num < first && num > second) {
                second = num;
            }
        }
    }
    return second;
};
