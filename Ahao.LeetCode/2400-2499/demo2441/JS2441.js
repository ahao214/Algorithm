var findMaxK = function (nums) {
    let k = -1;
    for (const x of nums) {
        for (const y of nums) {
            if (-x === y) {
                k = Math.max(k, x);
            }
        }
    }
    return k;
};


var findMaxK = function (nums) {
    let k = -1;
    const set = new Set();
    for (const x of nums) {
        set.add(x);
    }
    for (const x of nums) {
        if (set.has(-x)) {
            k = Math.max(k, x);
        }
    }
    return k;
};



var findMaxK = function (nums) {
    nums.sort((a, b) => a - b);
    for (let i = 0, j = nums.length - 1; i < j; j--) {
        while (i < j && nums[i] < -nums[j]) {
            i++;
        }
        if (nums[i] === -nums[j]) {
            return nums[j];
        }
    }
    return -1;
};
