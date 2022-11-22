//方法一：容斥原理 + 二分查找
const MOD = 1000000007;
var nthMagicalNumber = function (n, a, b) {
    let l = Math.min(a, b);
    let r = n * Math.min(a, b);
    const c = lcm(a, b);
    while (l <= r) {
        const mid = Math.floor((l + r) / 2);
        const cnt = Math.floor(mid / a) + Math.floor(mid / b) - Math.floor(mid / c);
        if (cnt >= n) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return (r + 1) % MOD;
}

const lcm = (a, b) => {
    return Math.floor(a * b / gcd(a, b));
}

const gcd = (a, b) => {
    return b !== 0 ? gcd(b, a % b) : a;
};




//方法二：找规律
const MOD = 1000000007;
var nthMagicalNumber = function (n, a, b) {
    const c = lcm(a, b);
    const m = Math.floor(c / a) + Math.floor(c / b) - 1;
    const r = n % m;
    const res = c * Math.floor(n / m) % MOD;
    if (r === 0) {
        return res;
    }
    let addA = a, addB = b;
    for (let i = 0; i < r - 1; ++i) {
        if (addA < addB) {
            addA += a;
        } else {
            addB += b;
        }
    }
    return (res + Math.min(addA, addB) % MOD) % MOD;
}

const lcm = (a, b) => {
    return Math.floor(a * b / gcd(a, b));
}

const gcd = (a, b) => {
    return b !== 0 ? gcd(b, a % b) : a;
};

