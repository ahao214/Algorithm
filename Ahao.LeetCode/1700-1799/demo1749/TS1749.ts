function maxAbsoluteSum(nums: number[]): number {
    let preMax: number = 0;
    let preMin: number = 0;
    let prefix: number = 0;
    nums.forEach((item) => {
        prefix += item;
        preMax = Math.max(preMax, prefix);
        preMin = Math.min(preMin, prefix);
    })
    return preMax - preMin;
};