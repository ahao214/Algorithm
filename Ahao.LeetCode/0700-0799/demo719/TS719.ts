﻿function smallestDistancePair(nums: number[], k: number): number {
    const count = (dist: number): number => {
        let ans = 0
        for (let i = 0, j = 0; j < nums.length; j++) {
            while (nums[j] - nums[i] > dist) {
                i++
            }
            ans += j - i
        }
        return ans
    }

    nums.sort((a, b) => a - b)
    let left = 0, right = nums[nums.length - 1] - nums[0] + 1
    while (left < right) {
        const mid = (left + right) >> 1
        if (count(mid) >= k) {
            right = mid
        } else {
            left = mid + 1
        }
    }
    return left
};
