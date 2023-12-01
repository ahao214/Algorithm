﻿var carPooling = function (trips, capacity) {
    let to_max = 0;
    for (const trip of trips) {
        to_max = Math.max(to_max, trip[2]);
    }

    const diff = new Array(to_max + 1).fill(0);
    for (const trip of trips) {
        diff[trip[1]] += trip[0];
        diff[trip[2]] -= trip[0];
    }

    let count = 0;
    for (let i = 0; i <= to_max; ++i) {
        count += diff[i];
        if (count > capacity) {
            return false;
        }
    }
    return true;
};
