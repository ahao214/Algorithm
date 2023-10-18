﻿var maxKelements = function (nums, k) {
    q = new MaxPriorityQueue();
    let ans = 0;
    for (const num of nums) {
        q.enqueue(num);
    }
    for (let i = 0; i < k; i++) {
        const x = q.dequeue().element;
        ans += x;
        q.enqueue(Math.ceil(x / 3));
    }
    return ans;
};
