//哈希表
var findPairs = function (nums, k) {
    const visited = new Set();
    const res = new Set();
    for (const num of nums) {
        if (visited.has(num - k)) {
            res.add(num - k);
        }
        if (visited.has(num + k)) {
            res.add(num);
        }
        visited.add(num);
    }
    return res.size;
};


//排序 + 双指针
var findPairs = function (nums, k) {
    nums.sort((a, b) => a - b);
    let n = nums.length, y = 0, res = 0;
    for (let x = 0; x < n; x++) {
        if (x === 0 || nums[x] !== nums[x - 1]) {
            while (y < n && (nums[y] < nums[x] + k || y <= x)) {
                y++;
            }
            if (y < n && nums[y] === nums[x] + k) {
                res++;
            }
        }
    }
    return res;
};
