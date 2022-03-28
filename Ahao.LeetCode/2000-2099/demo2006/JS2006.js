var countKDifference = function (nums, k) {
    let res = 0,
        n = nums.length;
    for (let i = 0; i < n; ++i) {
        for (let j = i + 1; j < n; ++j) {
            if (Math.abs(nums[i] - nums[j]) == k) {
                ++res;
            }
        }
    }
    return res;
};

var countKDifference1 = function (nums, k) {
    let res = 0,
        n = nums.length;
    const cnt = new Map();
    for (let j = 0; j < n; ++j) {
        res += (cnt.get(nums[j] - k) || 0) + (cnt.get(nums[j] + k) || 0);
        cnt.set(nums[j], (cnt.get(nums[j]) || 0) + 1);
    }
    return res;
};