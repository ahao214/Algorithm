var trailingZeroes = function (n) {
    let ans = 0;
    for (let i = 5; i <= n; i += 5) {
        for (let x = i; x % 5 == 0; x /= 5) {
            ++ans;
        }
    }
    return ans;
}

var trailingZeroes2 = function (n) {
    let ans = 0;
    while (n != 0) {
        n = Math.floor(n / 5);
        ans += n;
    }
    return ans;
}