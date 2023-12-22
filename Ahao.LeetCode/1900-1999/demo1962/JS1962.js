﻿var minStoneSum = function (piles, k) {
    const pq = new MaxPriorityQueue();
    for (const pile of piles) {
        pq.enqueue(pile, pile);
    }
    for (let i = 0; i < k; i++) {
        let pile = pq.front().element;
        pq.dequeue();
        pile -= Math.floor(pile / 2);
        pq.enqueue(pile, pile);
    }
    let sum = 0;
    while (!pq.isEmpty()) {
        sum += pq.front().element;
        pq.dequeue();
    }
    return sum;
};
