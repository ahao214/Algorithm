﻿class TreeSet {
    constructor(comparator) {
        this.set = new Set();
        this.comparator = comparator || ((a, b) => a - b);
        this.array = [];
    }

    add(item) {
        if (!this.set.has(item)) {
            this.set.add(item);
            this.array.push(item);
            this.array.sort(this.comparator);
        }
    }

    delete(item) {
        if (this.set.has(item)) {
            this.set.delete(item);
            this.array.splice(this.array.indexOf(item), 1);
        }
    }

    has(item) {
        return this.set.has(item);
    }

    get size() {
        return this.set.size;
    }

    toArray() {
        return [...this.array];
    }

    pollFirst() {
        const item = this.array.shift();
        this.set.delete(item);
        return item;
    }

    pollLast() {
        const item = this.array.pop();
        this.set.delete(item);
        return item;
    }
}

var DinnerPlates = function (capacity) {
    this.capacity = capacity;
    this.stack = [];
    this.top = [];
    this.poppedPos = new TreeSet();
};

DinnerPlates.prototype.push = function (val) {
    if (this.poppedPos.size === 0) {
        const pos = this.stack.length;
        this.stack.push(val);
        if (pos % this.capacity === 0) {
            this.top.push(0);
        }
        else {
            const stackPos = this.top.length - 1;
            const stackTop = this.top[stackPos];
            this.top.splice(stackPos, 1, stackTop + 1);
        }
    } else {
        const pos = this.poppedPos.pollFirst();
        this.stack.splice(pos, 1, val);
        const index = Math.floor(pos / this.capacity);
        const stackTop = this.top[index];
        this.top.splice(index, 1, stackTop + 1);
    }
};

DinnerPlates.prototype.pop = function () {
    while (this.stack.length !== 0 && this.poppedPos.has(this.stack.length - 1)) {
        this.stack.splice(this.stack.length - 1, 1);
        const pos = this.poppedPos.pollLast();
        if (pos % this.capacity === 0) {
            this.top.splice(this.top.length - 1, 1);
        }
    }
    if (this.stack.length === 0) {
        return -1;
    } else {
        const pos = this.stack.length - 1;
        const val = this.stack[pos];
        this.stack.splice(pos, 1);
        const index = this.top.length - 1;
        if (pos % this.capacity === 0) {
            this.top.splice(index, 1);
        } else {
            this.top.splice(index, 1, index - 1);
        }
        return val;
    }
};

DinnerPlates.prototype.popAtStack = function (index) {
    if (index >= this.top.length) {
        return -1;
    }
    const stackTop = this.top[index];
    if (stackTop < 0) {
        return -1;
    }
    this.top.splice(index, 1, stackTop - 1);
    const pos = index * this.capacity + stackTop;
    this.poppedPos.add(pos);
    return this.stack[pos];
};
