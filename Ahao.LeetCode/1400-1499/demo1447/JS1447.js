﻿var simplifiedFractions = function (n) {
    const ans = [];
    for (let denominator = 2; denominator <= n; ++denominator) {
        for (let numerator = 1; numerator < denominator; ++numerator) {
            if (gcd(numerator, denominator) == 1) {
                ans.push(numerator + "/" + denominator);
            }
        }
    }
    return ans;
};

const gcd = (a, b) => {
    if (b === 0) {
        return a;
    }
    return gcd(b, a % b);
};