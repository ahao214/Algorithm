﻿var repairCars = function (ranks, cars) {
    let l = 1;
    let r = ranks[0] * cars * cars;
    const check = (m) => {
        let cnt = 0;
        for (const x of ranks) {
            cnt += Math.floor(Math.sqrt(m / x));
        }
        return cnt >= cars;
    }

    while (l < r) {
        const m = (l + r) >> 1;
        if (check(m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return l;
};
