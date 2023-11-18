var maximumSum = function (nums) {
    let ans = -1;
    const mx = Array(82).fill(0); // 至多 9 个 9 相加
    for (const num of nums) {
        let s = 0; // num 的数位和
        for (let x = num; x; x = Math.floor(x / 10)) { // 枚举 num 的每个数位
            s += x % 10;
        }
        if (mx[s]) { // 说明左边也有数位和等于 s 的元素
            ans = Math.max(ans, mx[s] + num); // 更新答案的最大值
        }
        mx[s] = Math.max(mx[s], num); // 维护数位和等于 s 的最大元素
    }
    return ans;
};

