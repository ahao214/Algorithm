//方法一：图
var arrayNesting = function (nums) {
    let ans = 0, n = nums.length;
    const vis = new Array(n).fill(0);
    for (let i = 0; i < n; ++i) {
        let cnt = 0;
        while (!vis[i]) {
            vis[i] = true;
            i = nums[i];
            ++cnt;
        }
        ans = Math.max(ans, cnt);
    }
    return ans;
};



//方法二：原地标记
var arrayNesting = function (nums) {
    let ans = 0, n = nums.length;
    for (let i = 0; i < n; ++i) {
        let cnt = 0;
        while (nums[i] < n) {
            const num = nums[i];
            nums[i] = n;
            i = num;
            ++cnt;
        }
        ans = Math.max(ans, cnt);
    }
    return ans;
};
