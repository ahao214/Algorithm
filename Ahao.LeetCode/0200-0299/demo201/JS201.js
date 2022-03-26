/**
 * @param {number} left
 * @param {number} right
 * @return {number}
 */

//位移
var rangeBitwiseAnd = function (left, right) {
    let shift = 0;
    // 找到公共前缀
    while (m < n) {
        m >>= 1;
        n >>= 1;
        ++shift;
    }
    return m << shift;
};

//Brian Kernighan 算法
var rangeBitwiseAnd2 = function (m, n) {
    while (m < n) {
        // 抹去最右边的 1
        n = n & (n - 1);
    }
    return n;
};