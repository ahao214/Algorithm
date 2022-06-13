//基于比较的排序
var heightChecker = function (heights) {
    let n = heights.length, ans = 0;
    const expected = new Array(n).fill(0);
    expected.splice(0, n, ...heights);
    expected.sort((a, b) => a - b);
    for (let i = 0; i < n; ++i) {
        if (heights[i] !== expected[i]) {
            ++ans;
        }
    }
    return ans;
};


//计数排序
var heightChecker = function (heights) {
    const m = parseInt(_.max(heights));
    const cnt = new Array(m + 1).fill(0);
    for (const h of heights) {
        ++cnt[h];
    }

    let idx = 0, ans = 0;
    for (let i = 1; i <= m; ++i) {
        for (let j = 1; j <= cnt[i]; ++j) {
            if (heights[idx] !== i) {
                ++ans;
            }
            ++idx;
        }
    }
    return ans;
};
