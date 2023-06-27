﻿var minimumIncompatibility = function (nums, k) {
    const n = nums.length, group = n / k, inf = Infinity;
    const dp = new Array(1 << n).fill(inf);
    dp[0] = 0;
    const values = new Map();

    for (let mask = 1; mask < (1 << n); mask++) {
        if (countOnes(mask) !== group) {
            continue;
        }
        let mn = 20,
            mx = 0;
        const cur = new Set();
        for (let i = 0; i < n; i++) {
            if ((mask & (1 << i)) > 0) {
                if (cur.has(nums[i])) {
                    break;
                }
                cur.add(nums[i]);
                mn = Math.min(mn, nums[i]);
                mx = Math.max(mx, nums[i]);
            }
        }
        if (cur.size == group) {
            values.set(mask, mx - mn);
        }
    }

    for (let mask = 0; mask < (1 << n); mask++) {
        if (dp[mask] == inf) {
            continue;
        }
        const seen = new Map();
        for (let i = 0; i < n; i++) {
            if ((mask & (1 << i)) == 0) {
                seen.set(nums[i], i);
            }
        }
        if (seen.size < group) {
            continue;
        }
        let sub = 0;
        for (let v of seen.values()) {
            sub |= (1 << v);
        }
        let nxt = sub;
        while (nxt > 0) {
            if (values.has(nxt)) {
                dp[mask | nxt] = Math.min(dp[mask | nxt], dp[mask] + values.get(nxt));
            }
            nxt = (nxt - 1) & sub;
        }
    }

    return (dp[(1 << n) - 1] < inf) ? dp[(1 << n) - 1] : -1;
}

function countOnes(n) {
    let count = 0;
    while (n > 0) {
        count++;
        n &= n - 1;
    }
    return count;
}
