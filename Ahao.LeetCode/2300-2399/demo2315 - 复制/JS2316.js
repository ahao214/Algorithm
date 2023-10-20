﻿var countPairs = function (n, edges) {
    const uf = new UnionFind(n);
    for (const edge of edges) {
        x = edge[0], y = edge[1];
        uf.union(x, y);
    }
    let res = 0;
    for (let i = 0; i < n; i++) {
        res += n - uf.getSize(uf.find(i));
    }
    return res / 2;
};

class UnionFind {
    constructor(n) {
        this.sizes = new Array(n).fill(1);
        this.parents = new Array(n).fill(0).map((ele, index) => index);
    }

    find(x) {
        if (this.parents[x] == x) {
            return x;
        } else {
            this.parents[x] = this.find(this.parents[x]);
            return this.parents[x];
        }
    }

    union(x, y) {
        const rx = this.find(x);
        const ry = this.find(y);
        if (rx != ry) {
            if (this.sizes[rx] > this.sizes[ry]) {
                this.parents[ry] = rx;
                this.sizes[rx] += this.sizes[ry];
            } else {
                this.parents[rx] = ry;
                this.sizes[ry] += this.sizes[rx];
            }
        }
    }

    getSize(x) {
        return this.sizes[x];
    }
}
