﻿var minDeletion = function (nums) {
    let ans = 0, n = nums.length, check = true;
    for (let i = 0; i + 1 < n; i++) {
        if (nums[i] == nums[i + 1] && check) {
            ans++;
        } else {
            check = !check;
        }
    }
    if ((n - ans) % 2 != 0) {
        ans++;
    }
    return ans;
};
