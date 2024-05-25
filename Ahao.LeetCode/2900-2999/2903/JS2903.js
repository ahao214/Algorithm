﻿var findIndices = function (nums, indexDifference, valueDifference) {
    for (let i = 0; i < nums.length; i++) {
        for (let j = i; j < nums.length; j++) {
            if (j - i >= indexDifference && Math.abs(nums[j] - nums[i]) >= valueDifference) {
                return [i, j];
            }
        }
    }
    return [-1, -1];
};



var findIndices = function (nums, indexDifference, valueDifference) {
    let minIndex = 0, maxIndex = 0;
    for (let j = indexDifference; j < nums.length; j++) {
        let i = j - indexDifference;
        if (nums[i] < nums[minIndex]) {
            minIndex = i;
        }
        if (nums[j] - nums[minIndex] >= valueDifference) {
            return [minIndex, j];
        }
        if (nums[i] > nums[maxIndex]) {
            maxIndex = i;
        }
        if (nums[maxIndex] - nums[j] >= valueDifference) {
            return [maxIndex, j];
        }
    }
    return [-1, -1];
};

