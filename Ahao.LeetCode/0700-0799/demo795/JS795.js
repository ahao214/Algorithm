//一次遍历
var numSubarrayBoundedMax = function (nums, left, right) {
    let res = 0, last2 = -1, last1 = -1;
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] >= left && nums[i] <= right) {
            last1 = i;
        } else if (nums[i] > right) {
            last2 = i;
            last1 = -1;
        }
        if (last1 !== -1) {
            res += last1 - last2;
        }
    }
    return res;
};

//计数
var numSubarrayBoundedMax = function (nums, left, right) {
    return count(nums, right) - count(nums, left - 1);
}

const count = (nums, lower) => {
    let res = 0, cur = 0;
    for (const x of nums) {
        cur = x <= lower ? cur + 1 : 0;
        res += cur;
    }
    return res;
};

