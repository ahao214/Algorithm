﻿var countPairs = function (n, edges, queries) {
    const degree = new Array(n).fill(0);
    const cnt = new Map();
    for (var edge of edges) {
        let x = edge[0] - 1;
        let y = edge[1] - 1;
        if (x > y) {
            let tmp = x;
            x = y;
            y = tmp;
        }
        degree[x]++;
        degree[y]++;
        const key = x * n + y;
        cnt.set(key, cnt.has(key) ? cnt.get(key) + 1 : 1);
    }
    const arr = Array.from(degree);
    const ans = new Array(queries.length);
    arr.sort((a, b) => a - b);
    for (let k = 0; k < queries.length; k++) {
        const bound = queries[k];
        let total = 0;
        for (let i = 0; i < n; i++) {
            let j = binarySearch(arr, i + 1, n - 1, bound - arr[i]);
            total += n - j;
        }
        for (var [val, freq] of cnt.entries()) {
            let x = Math.floor(val / n);
            let y = val % n;
            if (degree[x] + degree[y] > bound && degree[x] + degree[y] - freq <= bound) {
                total--;
            }
        }
        ans[k] = total;
    }
    return ans;
};

const binarySearch = (arr, low, high, target) => {
    let ans = high + 1;
    while (low <= high) {
        const mid = Math.floor((high - low + 1) / 2) + low;
        if (arr[mid] <= target) {
            low = mid + 1;
        } else {
            high = mid - 1;
            ans = mid;
        }
    }
    return ans;
}
