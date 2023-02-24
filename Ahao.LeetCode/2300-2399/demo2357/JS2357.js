var minimumOperations = function (nums) {
    let ans = 0;
    nums.sort((a, b) => a - b);
    const length = nums.length;
    for (let i = 0; i < length; i++) {
        if (nums[i] > 0) {
            subtract(nums, nums[i], i);
            ans++;
        }
    }
    return ans;
}

const subtract = (nums, x, startIndex) => {
    const length = nums.length;
    for (let i = startIndex; i < length; i++) {
        nums[i] -= x;
    }
};


//哈希集合
var minimumOperations = function (nums) {
    const set = new Set();
    for (const num of nums) {
        if (num > 0) {
            set.add(num);
        }
    }
    return set.size;
};

