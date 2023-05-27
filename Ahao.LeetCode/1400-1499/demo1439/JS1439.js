﻿var kthSmallest = function (mat, k) {
    const m = mat.length;
    let prev = mat[0];
    for (let i = 1; i < m; ++i) {
        prev = merge(prev, mat[i], k);
    }
    return prev[k - 1];
}

const merge = (f, g, k) => {
    if (g.length > f.length) {
        return merge(g, f, k);
    }

    const pq = new MinHeap((a, b) => a[2] < b[2]);
    for (let i = 0; i < g.length; ++i) {
        pq.add([0, i, f[0] + g[i]]);
    }

    const list = [];
    while (k > 0 && pq.size !== 0) {
        const entry = pq.poll();
        list.push(entry[2]);
        if (entry[0] + 1 < f.length) {
            pq.add([entry[0] + 1, entry[1], f[entry[0] + 1] + g[entry[1]]]);
        }
        --k;
    }

    const ans = new Array(list.length).fill(0);
    for (let i = 0; i < list.length; ++i) {
        ans[i] = list[i];
    }
    return ans;
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



var kthSmallest = function (mat, k) {
    const m = mat.length;
    let prev = mat[0];
    for (let i = 1; i < m; ++i) {
        prev = merge(prev, mat[i], k);
    }
    return prev[k - 1];
}

const merge = (f, g, k) => {
    let left = f[0] + g[0], right = f[f.length - 1] + g[g.length - 1], thres = 0;
    k = Math.min(k, f.length * g.length);
    while (left <= right) {
        const mid = Math.floor((left + right) / 2);
        let rptr = g.length - 1, cnt = 0;
        for (let lptr = 0; lptr < f.length; ++lptr) {
            while (rptr >= 0 && f[lptr] + g[rptr] > mid) {
                --rptr;
            }
            cnt += rptr + 1;
        }
        if (cnt >= k) {
            thres = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    const list = [];
    let index = 0;
    for (let i = 0; i < f.length; ++i) {
        for (let j = 0; j < g.length; ++j) {
            let sum = f[i] + g[j];
            if (sum < thres) {
                list.push(sum);
            } else {
                break;
            }
        }
    }
    while (list.length < k) {
        list.push(thres);
    }
    const ans = new Array(list.length).fill(0);
    for (let i = 0; i < list.length; ++i) {
        ans[i] = list[i];
    }
    ans.sort((a, b) => a - b);
    return ans;
};


