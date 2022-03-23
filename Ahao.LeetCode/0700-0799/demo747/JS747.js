﻿/**
 * @param {*} nums 
 * @returns 
 */

var dominantIdex = function (nums) {
    let m1 = -1,
        m2 = -1;
    let index = -1;
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] > m1) {
            m2 = m1;
            m1 = nums[i];
            index = i;
        } else if (nums[i] > m2) {
            m2 = nums[i];
        }
    }
    return m1 >= m2 * 2 ? index : -1;
};