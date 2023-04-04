var commonFactors = function (a, b) {
    let ans = 0;
    for (let x = 1; x <= Math.min(a, b); ++x) {
        if (a % x === 0 && b % x === 0) {
            ++ans;
        }
    }
    return ans;
};



var commonFactors = function (a, b) {
    let c = gcd(a, b), ans = 0;
    for (let x = 1; x * x <= c; ++x) {
        if (c % x === 0) {
            ++ans;
            if (x * x !== c) {
                ++ans;
            }
        }
    }
    return ans;
}

const gcd = (a, b) => {
    while (b !== 0) {
        a %= b;
        a ^= b;
        b ^= a;
        a ^= b;
    }
    return a;
};
