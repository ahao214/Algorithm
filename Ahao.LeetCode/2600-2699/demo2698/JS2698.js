﻿var punishmentNumber = function (n) {
    const dfs = (s, pos, tot, target) => {
        if (pos == s.length) {
            return tot == target;
        }
        let sum = 0;
        for (let i = pos; i < s.length; i++) {
            sum = sum * 10 + parseInt(s[i]);
            if (tot + sum > target) {
                break;
            }
            if (dfs(s, i + 1, tot + sum, target)) {
                return true;
            }
        }
        return false;
    }
    let res = 0;
    for (let i = 1; i <= n; i++) {
        let s = (i * i).toString();
        if (dfs(s, 0, 0, i)) {
            res += i * i;
        }
    }
    return res;
};
