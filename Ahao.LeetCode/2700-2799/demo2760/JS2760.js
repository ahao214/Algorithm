var isSatisfied = function (nums, l, r, threshold) {
    if (nums[l] % 2 != 0) {
        return false;
    }
    for (let i = l; i <= r; i++) {
        if (nums[i] > threshold || (i < r && nums[i] % 2 == nums[i + 1] % 2)) {
            return false;
        }
    }
    return true;
};

var longestAlternatingSubarray = function (nums, threshold) {
    let res = 0;
    for (let l = 0; l < nums.length; l++) {
        for (let r = 0; r < nums.length; r++) {
            if (isSatisfied(nums, l, r, threshold)) {
                res = Math.max(res, r - l + 1);
            }
        }
    }
    return res;
};



var longestAlternatingSubarray = function (nums, threshold) {
    let res = 0, dp = 0;
    for (let l = nums.length - 1; l >= 0; l--) {
        if (nums[l] > threshold) {
            dp = 0;
        } else if (l == nums.length - 1 || nums[l] % 2 != nums[l + 1] % 2) {
            dp++;
        } else {
            dp = 1;
        }
        if (nums[l] % 2 == 0) {
            res = Math.max(res, dp);
        }
    }
    return res;
};
