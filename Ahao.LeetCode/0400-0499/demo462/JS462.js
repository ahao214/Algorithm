//排序
var minMoves2 = function (nums) {
    nums.sort((a, b) => a - b);
    let n = nums.length, ret = 0, x = nums[Math.floor(n / 2)];
    for (let i = 0; i < n; i++) {
        ret += Math.abs(nums[i] - x);
    }
    return ret;
};

作者：LeetCode - Solution
链接：https://leetcode.cn/problems/minimum-moves-to-equal-array-elements-ii/solution/zui-shao-yi-dong-ci-shu-shi-shu-zu-yuan-xt3r2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。