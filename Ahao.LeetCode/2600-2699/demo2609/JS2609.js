﻿var findTheLongestBalancedSubstring = function (s) {
    let res = 0;
    const count = new Array(2).fill(0);
    for (let i = 0; i < s.length; i++) {
        if (s[i] == '1') {
            count[1]++;
            res = Math.max(res, 2 * Math.min(count[0], count[1]));
        } else if (i == 0 || s[i - 1] == '1') {
            count[0] = 1;
            count[1] = 0;
        } else {
            count[0]++;
        }
    }
    return res;
};
