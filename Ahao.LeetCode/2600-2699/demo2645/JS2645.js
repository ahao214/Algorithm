var addMinimum = function (word) {
    const n = word.length;
    const d = new Array(n + 1).fill(0);
    for (let i = 1; i <= n; i++) {
        d[i] = d[i - 1] + 2;
        if (i > 1 && word[i - 1] > word[i - 2]) {
            d[i] = d[i - 1] - 1;
        }
    }
    return d[n];
};



var addMinimum = function (word) {
    const n = word.length;
    let res = word.charCodeAt(0) - word.charCodeAt(n - 1) + 2;
    for (let i = 1; i < n; i++) {
        res += (word.charCodeAt(i) - word.charCodeAt(i - 1) + 2) % 3;
    }
    return res;
};

var addMinimum = function (word) {
    const n = word.length;
    let cnt = 1;
    for (let i = 1; i < n; i++) {
        if (word[i] <= word[i - 1]) {
            cnt++;
        }
    }
    return cnt * 3 - n;
};

