var unequalTriplets = function (nums) {
    nums.sort();
    let res = 0, n = nums.length;
    for (let i = 0, j = 0; i < n; i = j) {
        while (j < n && nums[j] == nums[i]) {
            j++;
        }
        res += i * (j - i) * (n - j);
    }
    return res;
};



var unequalTriplets = function (nums) {
    let count = {}, res = 0, n = nums.length, t = 0;
    for (let x of nums) {
        count[x] = count[x] || 0;
        count[x]++;
    }
    for (let k in count) {
        res += t * count[k] * (n - t - count[k]);
        t += count[k];
    }
    return res;
};