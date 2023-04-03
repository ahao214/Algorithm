const INF = 0x3f3f3f3f;
var mergeStones = function (stones, k) {
    const n = stones.length;
    if ((n - 1) % (k - 1) !== 0) {
        return -1;
    }
    const d = new Array(n).fill(0).map(() => new Array(n).fill(0).map(() => new Array(k + 1).fill(-1)));
    const sum = new Array(n).fill(0);
    // 初始化
    for (let i = 0, s = 0; i < n; i++) {
        d[i][i][1] = 0;
        s += stones[i];
        sum[i] = s;
    }

    const get = (l, r, t) => {
        // 若 d[l][r][t] 不为 -1，表示已经在之前的递归被求解过，直接返回答案
        if (d[l][r][t] !== -1) {
            return d[l][r][t];
        }
        // 当石头堆数小于 t 时，一定无解
        if (t > r - l + 1) {
            return INF;
        }
        if (t === 1) {
            const res = get(l, r, k);
            if (res === INF) {
                return d[l][r][t] = INF;
            }
            return d[l][r][t] = res + (sum[r] - (l === 0 ? 0 : sum[l - 1]));
        }
        let val = INF;
        for (let p = l; p < r; p += (k - 1)) {
            val = Math.min(val, get(l, p, 1) + get(p + 1, r, t - 1));
        }
        return d[l][r][t] = val;
    }

    const res = get(0, n - 1, 1);
    return res;
};



const INF = 0x3f3f3f3f;
var mergeStones = function (stones, k) {
    const n = stones.length;
    if ((n - 1) % (k - 1) !== 0) {
        return -1;
    }

    const d = new Array(n).fill(0).map(() => new Array(n).fill(0).map(() => new Array(k + 1).fill(INF)));
    const sum = new Array(n).fill(0);

    for (let i = 0, s = 0; i < n; i++) {
        d[i][i][1] = 0;
        s += stones[i];
        sum[i] = s;
    }

    for (let len = 2; len <= n; len++) {
        for (let l = 0; l < n && l + len - 1 < n; l++) {
            let r = l + len - 1;
            for (let t = 2; t <= k; t++) {
                for (let p = l; p < r; p += k - 1) {
                    d[l][r][t] = Math.min(d[l][r][t], d[l][p][1] + d[p + 1][r][t - 1]);
                }
            }
            d[l][r][1] = Math.min(d[l][r][1], d[l][r][k] + sum[r] - (l === 0 ? 0 : sum[l - 1]));
        }
    }
    return d[0][n - 1][1];
};



const INF = 0x3f3f3f3f;
var mergeStones = function (stones, k) {
    const n = stones.length;
    if ((n - 1) % (k - 1) !== 0) {
        return -1;
    }

    const d = new Array(n).fill(0).map(() => new Array(n).fill(INF));
    const sum = new Array(n).fill(0);

    for (let i = 0, s = 0; i < n; i++) {
        d[i][i] = 0;
        s += stones[i];
        sum[i] = s;
    }

    for (let len = 2; len <= n; len++) {
        for (let l = 0; l < n && l + len - 1 < n; l++) {
            let r = l + len - 1;
            for (let p = l; p < r; p += k - 1) {
                d[l][r] = Math.min(d[l][r], d[l][p] + d[p + 1][r]);
            }
            if ((r - l) % (k - 1) === 0) {
                d[l][r] += sum[r] - (l === 0 ? 0 : sum[l - 1]);
            }
        }
    }
    return d[0][n - 1];
};
