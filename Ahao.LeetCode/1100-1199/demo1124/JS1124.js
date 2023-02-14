//贪心
var longestWPI = function (hours) {
    const n = hours.length;
    const s = new Array(n + 1).fill(0);
    const stk = [0];
    for (let i = 1; i <= n; i++) {
        s[i] = s[i - 1] + (hours[i - 1] > 8 ? 1 : -1);
        if (s[stk[stk.length - 1]] > s[i]) {
            stk.push(i);
        }
    }

    let res = 0;
    for (let r = n; r >= 1; r--) {
        while (stk.length && s[stk[stk.length - 1]] < s[r]) {
            res = Math.max(res, r - stk.pop());
        }
    }
    return res;
};


//哈希表
var longestWPI = function (hours) {
    const n = hours.length;
    const map = new Map();
    let s = 0, res = 0;
    for (let i = 0; i < n; i++) {
        s += hours[i] > 8 ? 1 : -1;
        if (s > 0) {
            res = Math.max(res, i + 1);
        } else {
            if (map.has(s - 1)) {
                res = Math.max(res, i - map.get(s - 1));
            }
        }
        if (!map.has(s)) {
            map.set(s, i);
        }
    }
    return res;
};
