﻿var pickGifts = function (gifts, k) {
    const pq = new MaxPriorityQueue();
    gifts.map(v => {
        pq.enqueue(v);
    });
    while (k > 0) {
        let x = pq.dequeue().element;
        pq.enqueue(Math.floor(Math.sqrt(x)));
        k--;
    }
    let res = 0;
    while (pq.size() > 0) {
        res += pq.dequeue().element;
    }
    return res;
};
