//方法一：哈希表
var containsNearbyDuplicate = function (nums, k) {
    const map = new Map();
    const length = nums.length;
    for (let i = 0; i < length; i++) {
        const num = nums[i];
        if (map.has(num) && i - map.get(num) <= k) {
            return true;
        }
        map.set(num, i);
    }
    return false;
};

//方法二：滑动窗口
var containsNearbyDuplicate1 = function (nums, k) {
    const set = new Set();
    const length = nums.length;
    for (let i = 0; i < length; i++) {
        if (i > k) {
            set.delete(nums[i - k - 1]);
        }
        if (set.has(nums[i])) {
            return true;
        }
        set.add(nums[i])
    }
    return false;
};