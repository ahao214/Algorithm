﻿var maximumSumQueries = function (nums1, nums2, queries) {
    const sortedNums = nums1.map((x, i) => [x, nums2[i]]);
    const sortedQueries = queries.map((x, i) => [i, ...x]);
    sortedNums.sort((a, b) => b[0] - a[0]);
    sortedQueries.sort((a, b) => b[1] - a[1]);

    const answer = new Array(queries.length).fill(-1);
    const stack = [];
    let j = 0;
    for (const q of sortedQueries) {
        const i = q[0];
        const x = q[1];
        const y = q[2];
        while (j < sortedNums.length && sortedNums[j][0] >= x) {
            const num1 = sortedNums[j][0];
            const num2 = sortedNums[j][1];
            while (stack.length > 0 && stack[stack.length - 1][1] <= num1 + num2) {
                stack.pop();
            }
            if (stack.length == 0 || stack[stack.length - 1][0] < num2) {
                stack.push([num2, num1 + num2]);
            }
            j++;
        }
        const k = binarySearch(stack, y);
        if (k < stack.length) {
            answer[i] = stack[k][1];
        }
    }
    return answer;
};

function binarySearch(arr, target) {
    let low = 0, high = arr.length
    while (low < high) {
        const mid = low + Math.floor((high - low) / 2);
        if (arr[mid][0] >= target) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}
