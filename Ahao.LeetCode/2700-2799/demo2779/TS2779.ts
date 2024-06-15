function maximumBeautyTS(nums: number[], k: number): number {
    let res = 0, n = nums.length;
    nums.sort((x, y) => x - y);
    for (let i = 0, j = 0; i < n; i++) {
        while (nums[i] - 2 * k > nums[j]) {
            j++;
        }
        res = Math.max(res, i - j + 1);
    }
    return res;
};


function maximumBeautyTS2(nums: number[], k: number): number {
    let m = Math.max(...nums);
    let diff = new Array(m + 2).fill(0);
    for (let i = 0; i < nums.length; i++) {
        diff[Math.max(nums[i] - k, 0)]++;
        diff[Math.min(nums[i] + k + 1, m + 1)]--;
    }
    let res = 0, count = 0;
    for (let i = 0; i < diff.length; i++) {
        count += diff[i];
        res = Math.max(res, count);
    }
    return res;
};

