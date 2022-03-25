/**
* @param {number[]} nums
* @return {void} Do not return anything, modify nums in-place instead.
*/
var sortColors = function (nums) {
    var index = 0
    // 将等于0的元素放到开头
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] === 0) {
            [nums[i], nums[index]] = [nums[index], nums[i]]
            index++
        }
    }
    for (let j = index; j < nums.length; j++) {
        if (nums[j] === 1) {
            [nums[j], nums[index]] = [nums[index], nums[j]]
            index++
        }
    }
    return nums
};
