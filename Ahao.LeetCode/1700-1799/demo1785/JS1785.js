﻿var minElements = function (nums, limit, goal) {
    const sum = _.sum(nums);
    const diff = Math.abs(sum - goal);
    return Math.abs(Math.floor((diff + limit - 1) / limit));
};
