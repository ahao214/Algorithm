﻿var bestTeamScore = function (scores, ages) {
    const n = scores.length;
    const people = new Array(n).fill(0).map(() => new Array(2).fill(0));
    for (let i = 0; i < n; ++i) {
        people[i] = [scores[i], ages[i]];
    }
    people.sort((a, b) => a[0] !== b[0] ? a[0] - b[0] : a[1] - b[1]);
    const dp = new Array(n).fill(0);
    let res = 0;
    for (let i = 0; i < n; ++i) {
        for (let j = i - 1; j >= 0; --j) {
            if (people[j][1] <= people[i][1]) {
                dp[i] = Math.max(dp[i], dp[j]);
            }
        }
        dp[i] += people[i][0];
        res = Math.max(res, dp[i]);
    }
    return res;
};




var bestTeamScore = function (scores, ages) {
    const maxAge = _.max(ages);
    const t = new Array(maxAge + 1).fill(0);
    let res = 0;
    const n = scores.length;
    const people = new Array(n).fill(0).map(() => new Array(2).fill(0));
    for (let i = 0; i < n; ++i) {
        people[i] = [scores[i], ages[i]];
    }
    people.sort((a, b) => a[0] !== b[0] ? a[0] - b[0] : a[1] - b[1]);

    const lowbit = (x) => {
        return x & (-x);
    }

    const update = (i, val) => {
        for (; i <= maxAge; i += lowbit(i)) {
            t[i] = Math.max(t[i], val);
        }
    }

    const query = (i) => {
        let ret = 0;
        for (; i > 0; i -= lowbit(i)) {
            ret = Math.max(ret, t[i]);
        }
        return ret;
    };

    for (let i = 0; i < n; ++i) {
        const score = people[i][0], age = people[i][1], cur = score + query(age);
        update(age, cur);
        res = Math.max(res, cur);
    }
    return res;
}
