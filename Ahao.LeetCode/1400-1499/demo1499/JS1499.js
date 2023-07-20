﻿var findMaxValueOfEquation = function (points, k) {
    let res = Number.MIN_SAFE_INTEGER;
    const heap = new MinHeap((a, b) => a[0] < b[0]);
    for (const point of points) {
        const x = point[0], y = point[1];
        while (heap.size !== 0 && x - heap.peek()[1] > k) {
            heap.poll();
        }
        if (heap.size !== 0) {
            res = Math.max(res, x + y - heap.peek()[0]);
        }
        heap.add([x - y, x]);
    }
    return res;
};

class MinHeap {
    constructor(compareFunc = (a, b) => a < b) {
        this.compare = compareFunc;
        this.heap = [];
    }

    get size() {
        return this.heap.length;
    }

    peek() {
        return this.heap[0];
    }

    add(value) {
        this.heap.push(value);
        this.heapifyUp();
    }

    poll() {
        if (this.size === 0) {
            return null;
        }
        if (this.size === 1) {
            return this.heap.pop();
        }
        const max = this.heap[0];
        this.heap[0] = this.heap.pop();
        this.heapifyDown();
        return max;
    }

    heapifyUp() {
        let currentIndex = this.size - 1;
        while (currentIndex > 0) {
            const parentIndex = Math.floor((currentIndex - 1) / 2);
            if (this.compare(this.heap[currentIndex], this.heap[parentIndex])) {
                [this.heap[currentIndex], this.heap[parentIndex]] = [this.heap[parentIndex], this.heap[currentIndex]];
                currentIndex = parentIndex;
            } else {
                break;
            }
        }
    }

    heapifyDown() {
        let currentIndex = 0;
        while (currentIndex < this.size) {
            let largestIndex = currentIndex;
            const leftChildIndex = 2 * currentIndex + 1;
            const rightChildIndex = 2 * currentIndex + 2;
            if (leftChildIndex < this.size && this.compare(this.heap[leftChildIndex], this.heap[largestIndex])) {
                largestIndex = leftChildIndex;
            }
            if (rightChildIndex < this.size && this.compare(this.heap[rightChildIndex], this.heap[largestIndex])) {
                largestIndex = rightChildIndex;
            }
            if (largestIndex !== currentIndex) {
                [this.heap[currentIndex], this.heap[largestIndex]] = [this.heap[largestIndex], this.heap[currentIndex]];
                currentIndex = largestIndex;
            } else {
                break;
            }
        }
    }
}


var findMaxValueOfEquation = function (points, k) {
    let res = Number.MIN_SAFE_INTEGER;
    const queue = [];
    for (const point of points) {
        let x = point[0], y = point[1];
        while (queue.length !== 0 && x - queue[0][1] > k) {
            queue.shift();
        }
        if (queue.length !== 0) {
            res = Math.max(res, x + y + queue[0][0]);
        }
        while (queue.length !== 0 && y - x >= queue[queue.length - 1][0]) {
            queue.pop();
        }
        queue.push([y - x, x]);
    }
    return res;
};
