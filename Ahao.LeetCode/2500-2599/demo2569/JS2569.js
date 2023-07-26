﻿
var handleQuery = function (nums1, nums2, queries) {
    const n = nums1.length;
    const m = queries.length;
    const tree = new SegTree(nums1);

    let sum = 0;
    for (const num of nums2) {
        sum += num;
    }
    const list = [];
    for (let i = 0; i < m; i++) {
        if (queries[i][0] === 1) {
            let l = queries[i][1];
            let r = queries[i][2];
            tree.reverseRange(l, r);
        } else if (queries[i][0] === 2) {
            sum += tree.sumRange(0, n - 1) * queries[i][1];
        } else if (queries[i][0] === 3) {
            list.push(sum);
        }
    }
    const ans = new Array(list.length).fill(0);
    for (let i = 0; i < list.length; i++) {
        ans[i] = list[i];
    }
    return ans;
}

class SegTree {
    constructor(nums) {
        const n = nums.length;
        this.arr = new SegNode(n * 4 + 1);
        this.build(1, 0, n - 1, nums);
    }

    sumRange(left, right) {
        return this.query(1, left, right);
    }

    reverseRange(left, right) {
        this.modify(1, left, right);
    }

    build(id, l, r, nums) {
        this.arr[id] = new SegNode();
        this.arr[id].l = l;
        this.arr[id].r = r;
        this.arr[id].lazytag = false;
        if (l === r) {
            this.arr[id].sum = nums[l];
            return;
        }
        let mid = (l + r) >> 1;
        this.build(2 * id, l, mid, nums);
        this.build(2 * id + 1, mid + 1, r, nums);
        this.arr[id].sum = this.arr[2 * id].sum + this.arr[2 * id + 1].sum;
    }

    /* pushdown函数：下传懒标记，即将当前区间的修改情况下传到其左右孩子结点 */
    pushdown(x) {
        if (this.arr[x].lazytag) {
            this.arr[2 * x].lazytag = !this.arr[2 * x].lazytag;
            this.arr[2 * x].sum = this.arr[2 * x].r - this.arr[2 * x].l + 1 - this.arr[2 * x].sum;
            this.arr[2 * x + 1].lazytag = !this.arr[2 * x + 1].lazytag;
            this.arr[2 * x + 1].sum = this.arr[2 * x + 1].r - this.arr[2 * x + 1].l + 1 - this.arr[2 * x + 1].sum;
            this.arr[x].lazytag = false;
        }
    }

    /* 区间修改 */
    modify(id, l, r) {
        if (this.arr[id].l >= l && this.arr[id].r <= r) {
            this.arr[id].sum = (this.arr[id].r - this.arr[id].l + 1) - this.arr[id].sum;
            this.arr[id].lazytag = !this.arr[id].lazytag;
            return;
        }
        this.pushdown(id);
        let mid = (this.arr[id].l + this.arr[id].r) >> 1;
        if (this.arr[2 * id].r >= l) {
            this.modify(2 * id, l, r);
        }
        if (this.arr[2 * id + 1].l <= r) {
            this.modify(2 * id + 1, l, r);
        }
        this.arr[id].sum = this.arr[2 * id].sum + this.arr[2 * id + 1].sum;
    }

    /* 区间查询 */
    query(id, l, r) {
        if (this.arr[id].l >= l && this.arr[id].r <= r) {
            return this.arr[id].sum;
        }
        if (this.arr[id].r < l || this.arr[id].l > r) {
            return 0;
        }
        this.pushdown(id);
        let res = 0;
        if (this.arr[2 * id].r >= l) {
            res += this.query(2 * id, l, r);
        }
        if (this.arr[2 * id + 1].l <= r) {
            res += this.query(2 * id + 1, l, r);
        }
        return res;
    }
}

class SegNode {
    constructor() {
        this.l = 0;
        this.r = 0;
        this.sum = 0;
        this.lazytag = false;
    }
}
