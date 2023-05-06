﻿var minNumberOfFrogs = function (croakOfFrogs) {
    if (croakOfFrogs.length % 5 !== 0) {
        return -1;
    }
    let res = 0, frogNum = 0;
    const cnt = new Array(4).fill(0);
    const map = new Map();
    map.set('c', 0);
    map.set('r', 1);
    map.set('o', 2);
    map.set('a', 3);
    map.set('k', 4);
    for (let i = 0; i < croakOfFrogs.length; i++) {
        const c = croakOfFrogs[i];
        const t = map.get(c);
        if (t === 0) {
            cnt[t]++;
            frogNum++;
            if (frogNum > res) {
                res = frogNum;
            }
        } else {
            if (cnt[t - 1] === 0) {
                return -1;
            }
            cnt[t - 1]--;
            if (t === 4) {
                frogNum--;
            } else {
                cnt[t]++;
            }
        }
    }
    if (frogNum > 0) {
        return -1;
    }
    return res;
};
