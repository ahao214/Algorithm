var partitionDisjoint = function (nums) {
    const n = nums.length;
    const minRight = new Array(n).fill(0);
    minRight[n - 1] = nums[n - 1];
    for (let i = n - 2; i >= 0; i--) {
        minRight[i] = Math.min(nums[i], minRight[i + 1]);
    }

    let maxLeft = 0;
    for (let i = 0; i < n - 1; i++) {
        maxLeft = Math.max(maxLeft, nums[i]);
        if (maxLeft <= minRight[i + 1]) {
            return i + 1;
        }
    }
    return n - 1;
};


var partitionDisjoint = function (nums) {
    const n = nums.length;
    let leftMax = nums[0], leftPos = 0, curMax = nums[0];
    for (let i = 1; i < n - 1; i++) {
        curMax = Math.max(curMax, nums[i]);
        if (nums[i] < leftMax) {
            leftMax = curMax;
            leftPos = i;
        }
    }
    return leftPos + 1;
};
