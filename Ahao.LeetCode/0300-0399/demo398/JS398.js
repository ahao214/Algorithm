﻿var Solution = function (nums) {
    this.pos = new Map();
    for (let i = 0; i < nums.length; ++i) {
        if (!this.pos.has(nums[i])) {
            this.pos.set(nums[i], []);
        }

        this.pos.get(nums[i]).push(i);
    }
};

Solution.prototype.pick = function (target) {
    const indices = this.pos.get(target);
    return indices[Math.floor(Math.random() * indices.length)];
};
