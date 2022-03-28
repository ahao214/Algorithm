var nearestPalindromic = function (n) {
    const bit = BigInt(n);
    const nums = [bit - 1 n, bit + 1 n];
    while (true) {
        const d1 = getDistance(nums[0]);
        if (d1 === 0) break;
        nums[0] -= BigInt(d1);
    }
    while (true) {
        const d2 = getDistance(nums[1]);
        if (d2 === 0) break;
        nums[1] += BigInt(d2);
    }
    return bit - nums[0] <= nums[1] - bit ? String(nums[0]) : String(nums[1])
};

function getDistance(n) {
    const s = n + '';
    let i = 0;
    let j = s.length - 1;
    while (i < j) {
        if (s[i++] !== s[j--]) return 10 ** (i - 1);
    }
    return 0;
}