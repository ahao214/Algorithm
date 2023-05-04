﻿var maxTotalFruits = function (fruits, startPos, k) {
    const n = fruits.length;
    const sum = new Array(n + 1).fill(0);
    const indices = new Array(n).fill(0);
    sum[0] = 0;
    for (let i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + fruits[i][1];
        indices[i] = fruits[i][0];
    }
    let ans = 0;
    for (let x = 0; x <= Math.floor(k / 2); x++) {
        /* 向左走 x 步，再向右走 k - x 步 */
        let y = k - 2 * x;
        let left = startPos - x;
        let right = startPos + y;
        let start = lowerBound(indices, 0, n - 1, left);
        let end = upperBound(indices, 0, n - 1, right);
        ans = Math.max(ans, sum[end] - sum[start]);
        /* 向右走 x 步，再向左走 k - x 步 */
        y = k - 2 * x;
        left = startPos - y;
        right = startPos + x;
        start = lowerBound(indices, 0, n - 1, left);
        end = upperBound(indices, 0, n - 1, right);
        ans = Math.max(ans, sum[end] - sum[start]);
    }
    return ans;
}

const lowerBound = (arr, left, right, val) => {
    let res = right + 1;
    while (left <= right) {
        const mid = left + Math.floor((right - left) / 2);
        if (arr[mid] >= val) {
            res = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return res;
}

const upperBound = (arr, left, right, val) => {
    let res = right + 1;
    while (left <= right) {
        const mid = left + Math.floor((right - left) / 2);
        if (arr[mid] > val) {
            res = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return res;
};



var maxTotalFruits = function (fruits, startPos, k) {
    let left = 0;
    let right = 0;
    const n = fruits.length;
    let sum = 0;
    let ans = 0;
    // 每次固定住窗口右边界
    while (right < n) {
        sum += fruits[right][1];
        // 移动左边界
        while (left <= right && step(fruits, startPos, left, right) > k) {
            sum -= fruits[left][1];
            left++;
        }
        ans = Math.max(ans, sum);
        right++;
    }
    return ans;
}

const step = (fruits, startPos, left, right) => {
    return Math.min(Math.abs(startPos - fruits[right][0]), Math.abs(startPos - fruits[left][0])) + fruits[right][0] - fruits[left][0];
};
