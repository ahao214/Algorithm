var kthGrammar = function (n, k) {
    if (n === 1) {
        return 0;
    }
    return (k & 1) ^ 1 ^ kthGrammar(n - 1, (k + 1) / 2);
};


var kthGrammar = function (n, k) {
    if (k === 1) {
        return 0;
    }
    if (k > (1 << (n - 2))) {
        return 1 ^ kthGrammar(n - 1, k - (1 << (n - 2)));
    }
    return kthGrammar(n - 1, k);
};


var kthGrammar = function (n, k) {
    k--;
    let res = 0;
    while (k > 0) {
        k &= k - 1;
        res ^= 1;
    }
    return res;
};