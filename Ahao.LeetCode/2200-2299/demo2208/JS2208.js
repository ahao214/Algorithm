﻿var halveArray = function (nums) {
    const pq = new MaxPriorityQueue();
    for (const num of nums) {
        pq.enqueue(num);
    }
    let res = 0;
    let sum1 = nums.reduce((acc, curr) => acc + curr, 0);
    let sum2 = 0;
    while (sum2 < sum1 / 2) {
        const x = pq.dequeue().element;
        sum2 += x / 2;
        pq.enqueue(x / 2);
        res++;
    }
    return res;
};
