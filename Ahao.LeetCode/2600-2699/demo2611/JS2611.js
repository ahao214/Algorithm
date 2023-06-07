﻿var miceAndCheese = function (reward1, reward2, k) {
    let ans = 0;
    let n = reward1.length;
    let diffs = new Array(n);
    for (let i = 0; i < n; i++) {
        ans += reward2[i];
        diffs[i] = reward1[i] - reward2[i];
    }
    diffs.sort((a, b) => a - b);
    for (let i = 1; i <= k; i++) {
        ans += diffs[n - i];
    }
    return ans;
}