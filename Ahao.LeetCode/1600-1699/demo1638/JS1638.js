﻿var countSubstrings = function (s, t) {
    const m = s.length, n = t.length;
    let ans = 0;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            let diff = 0;
            for (let k = 0; i + k < m && j + k < n; k++) {
                diff += s[i + k] === t[j + k] ? 0 : 1;
                if (diff > 1) {
                    break;
                } else if (diff === 1) {
                    ans++;
                }
            }
        }
    }
    return ans;
};


var countSubstrings = function (s, t) {
    const m = s.length, n = t.length;
    const dpl = new Array(m + 1).fill(0).map(() => new Array(n + 1).fill(0));
    const dpr = new Array(m + 1).fill(0).map(() => new Array(n + 1).fill(0));
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            dpl[i + 1][j + 1] = s[i] === t[j] ? (dpl[i][j] + 1) : 0;
        }
    }
    for (let i = m - 1; i >= 0; i--) {
        for (let j = n - 1; j >= 0; j--) {
            dpr[i][j] = s[i] === t[j] ? (dpr[i + 1][j + 1] + 1) : 0;
        }
    }
    let ans = 0;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (s[i] !== t[j]) {
                ans += (dpl[i][j] + 1) * (dpr[i + 1][j + 1] + 1);
            }
        }
    }
    return ans;
};
