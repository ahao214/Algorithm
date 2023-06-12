﻿var unequalTriplets = function (nums) {
    nums.sort();
    let res = 0, n = nums.length;
    for (let i = 0, j = 0; i < n; i = j) {
        while (j < n && nums[j] == nums[i]) {
            j++;
        }
        res += i * (j - i) * (n - j);
    }
    return res;
};



