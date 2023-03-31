var arithmeticTriplets = function (nums, diff) {
    let ans = 0;
    const n = nums.length;
    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            if (nums[j] - nums[i] !== diff) {
                continue;
            }
            for (let k = j + 1; k < n; k++) {
                if (nums[k] - nums[j] === diff) {
                    ans++;
                }
            }
        }
    }
    return ans;
};


var arithmeticTriplets = function (nums, diff) {
    const set = new Set();
    for (const x of nums) {
        set.add(x);
    }
    let ans = 0;
    for (const x of nums) {
        if (set.has(x + diff) && set.has(x + 2 * diff)) {
            ans++;
        }
    }
    return ans;
};
