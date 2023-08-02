﻿var flipgame = function (fronts, backs) {
    const same = new Set();
    for (let i = 0; i < fronts.length; i++) {
        if (fronts[i] === backs[i]) {
            same.add(fronts[i]);
        }
    }
    let res = 3000;
    for (let x of fronts) {
        if (x < res && !same.has(x)) {
            res = x;
        }
    }
    for (let x of backs) {
        if (x < res && !same.has(x)) {
            res = x;
        }
    }
    return res % 3000;
};
