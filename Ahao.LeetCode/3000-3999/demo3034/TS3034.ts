function maxOperationsTS(nums: number[]): number {
    const n = nums.length;

    const helper = (i: number, j: number, target: number): number => {
        const memo: number[][] = Array.from({ length: n }, () => Array(n).fill(-1));
        const dfs = (i: number, j: number): number => {
            if (i >= j) {
                return 0;
            }
            if (memo[i][j] !== -1) {
                return memo[i][j];
            }
            let ans = 0;
            if (nums[i] + nums[i + 1] === target) {
                ans = Math.max(ans, 1 + dfs(i + 2, j));
            }
            if (nums[j - 1] + nums[j] === target) {
                ans = Math.max(ans, 1 + dfs(i, j - 2));
            }
            if (nums[i] + nums[j] === target) {
                ans = Math.max(ans, 1 + dfs(i + 1, j - 1));
            }
            memo[i][j] = ans;
            return ans;
        };
        return dfs(i, j);
    };

    let res = 0;
    res = Math.max(res, helper(0, n - 1, nums[0] + nums[n - 1]));
    res = Math.max(res, helper(0, n - 1, nums[0] + nums[1]));
    res = Math.max(res, helper(0, n - 1, nums[n - 2] + nums[n - 1]));
    return res;
};
