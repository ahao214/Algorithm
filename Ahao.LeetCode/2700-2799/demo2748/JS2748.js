var countBeautifulPairs = function (nums) {
    let res = 0;
    let n = nums.length;

    for (let i = 0; i < n; i++) {
        while (nums[i] >= 10) {
            nums[i] = Math.floor(nums[i] / 10);
        }
        for (let j = i + 1; j < n; j++) {
            if (gcd(nums[i], nums[j] % 10) === 1) {
                res++;
            }
        }
    }
    return res;
};



var countBeautifulPairs = function (nums) {
    let res = 0;
    let cnt = new Array(10).fill(0);

    for (let x of nums) {
        for (let y = 1; y <= 9; y++) {
            if (gcd(x % 10, y) === 1) {
                res += cnt[y];
            }
        }
        while (x >= 10) {
            x = Math.floor(x / 10);
        }
        cnt[x]++;
    }
    return res;
};

function gcd(a, b) {
    return b === 0 ? a : gcd(b, a % b);
}
