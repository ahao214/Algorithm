﻿//方法一：两次遍历
var sortArrayByParity = function (nums) {
    let n = nums.length, index = 0;
    const res = new Array(n).fill(0);
    for (const num of nums) {
        if (num % 2 === 0) {
            res[index++] = num;
        }
    }
    for (const num of nums) {
        if (num % 2 === 1) {
            res[index++] = num;
        }
    }
    return res;
};


//方法二：双指针 + 一次遍历
var sortArrayByParity = function (nums) {
    const n = nums.length;
    const res = new Array(n).fill(0);
    let left = 0, right = n - 1;
    for (const num of nums) {
        if (num % 2 === 0) {
            res[left++] = num;
        } else {
            res[right--] = num;
        }
    }
    return res;
};

//方法三：原地交换
var sortArrayByParity = function (nums) {
    let left = 0, right = nums.length - 1;
    while (left < right) {
        while (left < right && nums[left] % 2 === 0) {
            left++;
        }
        while (left < right && nums[right] % 2 === 1) {
            right--;
        }
        if (left < right) {
            const temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            left++;
            right--;
        }
    }
    return nums;
};

