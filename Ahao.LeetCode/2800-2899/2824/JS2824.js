var countPairs = function (nums, target) {
    let res = 0;
    for (let i = 0; i < nums.length; i++) {
        for (let j = i + 1; j < nums.length; j++) {
            if (nums[i] + nums[j] < target) {
                res++;
            }
        }
    }
    return res;
};


var countPairs = function (nums, target) {
    function binarySearch(nums, lo, hi, target) {
        let res = hi + 1;
        while (lo <= hi) {
            const mid = lo + Math.floor((hi - lo) / 2);
            if (nums[mid] >= target) {
                res = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return res;
    }
    nums.sort((a, b) => a - b);
    let res = 0;
    for (let i = 0; i < nums.length; i++) {
        res += binarySearch(nums, 0, i - 1, target - nums[i]);
    }
    return res;
};


var countPairs = function (nums, target) {
    nums.sort((a, b) => a - b);
    let res = 0;
    for (let i = 0, j = nums.length - 1; i < j; i++) {
        while (i < j && nums[i] + nums[j] >= target) {
            j--;
        }
        res += j - i;
    }
    return res;
};
