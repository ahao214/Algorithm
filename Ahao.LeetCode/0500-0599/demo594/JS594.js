//方法一：枚举
var findLHS = function (nums) {
    nums.sort((a, b) => a - b);
    let begin = 0;
    let res = 0;
    for (let end = 0; end < nums.length; end++) {
        while (nums[end] - nums[begin] > 1) {
            begin++;
        }
        if (nums[end] - nums[begin] === 1) {
            res = Math.max(res, end - begin + 1);
        }
    }
    return res;
};

//方法二：哈希表
var findLHS2 = function (nums) {
    const cnt = new Map();
    let res = 0;
    for (const num of nums) {
        cnt.set(num, (cnt.get(num) || 0) + 1);
    }
    for (const key of cnt.keys()) {
        if (cnt.has(key + 1)) {
            res = Math.max(res, cnt.get(key) + cnt.get(key + 1));
        }
    }
    return res;
}