﻿var miceAndCheese = function (reward1, reward2, k) {
    let ans = 0;
    let n = reward1.length;
    let diffs = new Array(n);
    for (let i = 0; i < n; i++) {
        ans += reward2[i];
        diffs[i] = reward1[i] - reward2[i];
    }
    diffs.sort((a, b) => a - b);
    for (let i = 1; i <= k; i++) {
        ans += diffs[n - i];
    }
    return ans;
}


class Heap {
    constructor() {
        this.heap = [];
    }

    push(value) {
        this.heap.push(value);
        this.bubbleUp(this.heap.length - 1);
    }

    poll() {
        const result = this.heap[0];
        const end = this.heap.pop();
        if (this.heap.length > 0) {
            this.heap[0] = end;
            this.sinkDown(0);
        }
        return result;
    }

    size() {
        return this.heap.length;
    }

    isEmpty() {
        return this.heap.length === 0;
    }

    bubbleUp(index) {
        const element = this.heap[index];
        while (index > 0) {
            const parentIndex = Math.floor((index - 1) / 2);
            const parent = this.heap[parentIndex];
            if (element >= parent) {
                break;
            }
            this.heap[parentIndex] = element;
            this.heap[index] = parent;
            index = parentIndex;
        }
    }

    sinkDown(index) {
        const element = this.heap[index];
        const length = this.heap.length;
        while (true) {
            let leftChildIndex = 2 * index + 1;
            let rightChildIndex = 2 * index + 2;
            let leftChild, rightChild;
            let swap = null;

            if (leftChildIndex < length) {
                leftChild = this.heap[leftChildIndex];
                if (leftChild < element) {
                    swap = leftChildIndex;
                }
            }

            if (rightChildIndex < length) {
                rightChild = this.heap[rightChildIndex];
                if ((swap === null && rightChild < element) ||
                    (swap !== null && rightChild < leftChild)) {
                    swap = rightChildIndex;
                }
            }

            if (swap === null) {
                break;
            }

            this.heap[index] = this.heap[swap];
            this.heap[swap] = element;
            index = swap;
        }
    }
}

var miceAndCheese = function (reward1, reward2, k) {
    let ans = 0;
    let n = reward1.length;
    let pq = new Heap();
    for (let i = 0; i < n; i++) {
        ans += reward2[i];
        pq.push(reward1[i] - reward2[i]);
        if (pq.size() > k) {
            pq.poll();
        }
    }
    while (!pq.isEmpty()) {
        ans += pq.poll();
    }
    return ans;
}
