﻿function mostCompetitiveTS(nums: number[], k: number): number[] {
    const res: number[] = [];
    const n = nums.length;
    for (let i = 0; i < n; i++) {
        while (res.length > 0 && n - i + res.length > k && res[res.length - 1] > nums[i]) {
            res.pop();
        }
        res.push(nums[i]);
    }
    res.length = k;
    return res;
};
