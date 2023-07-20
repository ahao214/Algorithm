var maxSubarraySumCircular = function (nums) {
    let n = nums.length;
    const leftMax = new Array(n).fill(0);
    // 对坐标为 0 处的元素单独处理，避免考虑子数组为空的情况
    leftMax[0] = nums[0];
    let leftSum = nums[0];
    let pre = nums[0];
    let res = nums[0];
    for (let i = 1; i < n; i++) {
        pre = Math.max(pre + nums[i], nums[i]);
        res = Math.max(res, pre);
        leftSum += nums[i];
        leftMax[i] = Math.max(leftMax[i - 1], leftSum);
    }

    // 从右到左枚举后缀，固定后缀，选择最大前缀
    let rightSum = 0;
    for (let i = n - 1; i > 0; i--) {
        rightSum += nums[i];
        res = Math.max(res, rightSum + leftMax[i - 1]);
    }
    return res;
};


var maxSubarraySumCircular = function (nums) {
    let n = nums.length;
    const leftMax = new Array(n).fill(0);
    // 对坐标为 0 处的元素单独处理，避免考虑子数组为空的情况
    leftMax[0] = nums[0];
    let leftSum = nums[0];
    let pre = nums[0];
    let res = nums[0];
    for (let i = 1; i < n; i++) {
        pre = Math.max(pre + nums[i], nums[i]);
        res = Math.max(res, pre);
        leftSum += nums[i];
        leftMax[i] = Math.max(leftMax[i - 1], leftSum);
    }

    // 从右到左枚举后缀，固定后缀，选择最大前缀
    let rightSum = 0;
    for (let i = n - 1; i > 0; i--) {
        rightSum += nums[i];
        res = Math.max(res, rightSum + leftMax[i - 1]);
    }
    return res;
};

