var NumArray = function(nums) {
    this.nums = nums;
    const n = nums.length;
    size = Math.floor(Math.sqrt(n));
    this.sum = new Array(Math.floor((n + size - 1) / size)).fill(0); // n/size 向上取整
    for (let i = 0; i < n; i++) {
        this.sum[Math.floor(i / size)] += nums[i];
    }
};

NumArray.prototype.update = function(index, val) {
    this.sum[Math.floor(index / size)] += val - this.nums[index];
    this.nums[index] = val;
};

NumArray.prototype.sumRange = function(left, right) {
    const b1 = Math.floor(left / size), i1 = left % size, b2 = Math.floor(right / size), i2 = right % size;
    if (b1 === b2) { // 区间 [left, right] 在同一块中
        let sum = 0;
        for (let j = i1; j <= i2; j++) {
            sum += this.nums[b1 * size + j];
        }
        return sum;
    }
    let sum1 = 0;
    for (let j = i1; j < size; j++) {
        sum1 += this.nums[b1 * size + j];
    }
    let sum2 = 0;
    for (let j = 0; j <= i2; j++) {
        sum2 += this.nums[b2 * size + j];
    }
    let sum3 = 0;
    for (let j = b1 + 1; j < b2; j++) {
        sum3 += this.sum[j];
    }
    return sum1 + sum2 + sum3;
};


//线段树
var NumArray = function (nums) {
    n = nums.length;
    this.segmentTree = new Array(nums.length * 4).fill(0);
    this.build(0, 0, n - 1, nums);
};

NumArray.prototype.update = function (index, val) {
    this.change(index, val, 0, 0, n - 1);
};

NumArray.prototype.sumRange = function (left, right) {
    return this.range(left, right, 0, 0, n - 1);
};

NumArray.prototype.build = function (node, s, e, nums) {
    if (s === e) {
        this.segmentTree[node] = nums[s];
        return;
    }
    const m = s + Math.floor((e - s) / 2);
    this.build(node * 2 + 1, s, m, nums);
    this.build(node * 2 + 2, m + 1, e, nums);
    this.segmentTree[node] = this.segmentTree[node * 2 + 1] + this.segmentTree[node * 2 + 2];
}

NumArray.prototype.change = function (index, val, node, s, e) {
    if (s === e) {
        this.segmentTree[node] = val;
        return;
    }
    const m = s + Math.floor((e - s) / 2);
    if (index <= m) {
        this.change(index, val, node * 2 + 1, s, m);
    } else {
        this.change(index, val, node * 2 + 2, m + 1, e);
    }
    this.segmentTree[node] = this.segmentTree[node * 2 + 1] + this.segmentTree[node * 2 + 2];
}

NumArray.prototype.range = function (left, right, node, s, e) {
    if (left === s && right === e) {
        return this.segmentTree[node];
    }
    const m = s + Math.floor((e - s) / 2);
    if (right <= m) {
        return this.range(left, right, node * 2 + 1, s, m);
    } else if (left > m) {
        return this.range(left, right, node * 2 + 2, m + 1, e);
    } else {
        return this.range(left, m, node * 2 + 1, s, m) + this.range(m + 1, right, node * 2 + 2, m + 1, e);
    }
}
