//枚举
var countTriplets = function (nums) {
    const cnt = new Array(1 << 16).fill(0);
    for (const x of nums) {
        for (const y of nums) {
            ++cnt[x & y];
        }
    }
    let ans = 0;
    for (const x of nums) {
        for (let mask = 0; mask < (1 << 16); ++mask) {
            if ((x & mask) === 0) {
                ans += cnt[mask];
            }
        }
    }
    return ans;
};


//枚举+子集优化
var countTriplets = function (nums) {
    const cnt = new Array(1 << 16).fill(0);
    for (const x of nums) {
        for (const y of nums) {
            ++cnt[x & y];
        }
    }
    let ans = 0;
    for (let x of nums) {
        x = x ^ 0xffff;
        for (let sub = x; sub !== 0; sub = (sub - 1) & x) {
            ans += cnt[sub];
        }
        ans += cnt[0];
    }
    return ans;
};
