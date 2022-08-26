var maxProduct = function (nums) {
    nums.sort((a, b) => a - b);
    console.log(nums)
    return (nums[nums.length - 1] - 1) * (nums[nums.length - 2] - 1);
};


var maxProduct = function (nums) {
    let a = nums[0], b = nums[1];
    if (a < b) {
        const temp = a;
        a = b;
        b = temp;
    }
    for (let i = 2; i < nums.length; i++) {
        if (nums[i] > a) {
            b = a;
            a = nums[i];
        } else if (nums[i] > b) {
            b = nums[i];
        }
    }
    return (a - 1) * (b - 1);
};
