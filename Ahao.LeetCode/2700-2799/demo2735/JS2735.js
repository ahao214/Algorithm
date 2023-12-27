﻿var minCost = function (nums, x) {
    let n = nums.length;
    const f = [...nums];
    let ans = nums.reduce((accumulator, currentValue) => accumulator + currentValue, 0);

    for (let k = 1; k < n; k++) {
        for (let i = 0; i < n; i++) {
            f[i] = Math.min(f[i], nums[(i + k) % n])
        }
        sum = f.reduce((accumulator, currentValue) => accumulator + currentValue, 0);
        ans = Math.min(ans, k * x + sum);
    }
    return ans;
};
