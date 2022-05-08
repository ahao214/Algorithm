//方法一：将元素交换到对应的位置
var findDuplicates = function (nums) {
    const swap = (nums, index1, index2) => {
        const temp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = temp;
    };
    const n = nums.length;
    for (let i = 0; i < n; ++i) {
        while (nums[i] != nums[nums[i] - 1]) {
            swap(nums, i, nums[i] - 1);
        }
    }
    const ans = [];
    for (let i = 0; i < n; ++i) {
        if (nums[i] - 1 !== i) {
            ans.push(nums[i]);
        }
    }
    return ans;
}



//方法二：使用正负号作为标记
var findDuplicates = function (nums) {
    const n = nums.length;
    const ans = [];
    for (let i = 0; i < n; ++i) {
        const x = Math.abs(nums[i]);
        if (nums[x - 1] > 0) {
            nums[x - 1] = -nums[x - 1];
        } else {
            ans.push(x);
        }
    }
    return ans;
}
