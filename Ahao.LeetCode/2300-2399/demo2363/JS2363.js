﻿var mergeSimilarItems = function (items1, items2) {
    const map = new Map();
    for (const v of items1) {
        map.set(v[0], (map.get(v[0]) || 0) + v[1]);
    }
    for (const v of items2) {
        map.set(v[0], (map.get(v[0]) || 0) + v[1]);
    }

    const res = [];
    for (const [k, v] of map.entries()) {
        const pair = [];
        pair.push(k);
        pair.push(v);
        res.push(pair);
    }
    res.sort((a, b) => a[0] - b[0]);
    return res;
};
