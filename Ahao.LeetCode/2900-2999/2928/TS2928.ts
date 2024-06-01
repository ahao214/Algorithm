function distributeCandiesTS1(n: number, limit: number): number {
    let ans = 0;

    for (let i = 0; i <= limit; i++) {
        for (let j = 0; j <= limit; j++) {
            if (i + j > n) {
                break;
            }
            if (n - i - j <= limit) {
                ans++;
            }
        }
    }
    return ans;
};


function distributeCandiesTS2(n: number, limit: number): number {
    let ans = 0;
    for (let i = 0; i <= Math.min(limit, n); i++) {
        if (n - i > 2 * limit) {
            continue;
        }
        ans += Math.min(n - i, limit) - Math.max(0, n - i - limit) + 1;
    }
    return ans;
};


function calTS3(x: number): number {
    return x < 0 ? 0 : x * (x - 1) / 2;
}

function distributeCandies(n: number, limit: number): number {
    return cal(n + 2) - 3 * cal(n - limit + 1) + 3 * cal(n - (limit + 1) * 2 + 2) - cal(n - 3 * (limit + 1) + 2);
};
