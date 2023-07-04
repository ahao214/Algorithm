﻿var matrixSum = function (nums) {
    let res = 0;
    let m = nums.length;
    let n = nums[0].length;
    for (let i = 0; i < m; i++) {
        nums[i].sort((a, b) => a - b);
    }
    for (let j = 0; j < n; j++) {
        let maxVal = 0;
        for (let i = 0; i < m; i++) {
            maxVal = Math.max(maxVal, nums[i][j]);
        }
        res += maxVal;
    }
    return res;
}
