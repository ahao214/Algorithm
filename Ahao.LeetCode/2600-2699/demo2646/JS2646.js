var minimumTotalPrice = function (n, edges, price, trips) {
    const next = new Array(n).fill(0).map(() => new Array());
    for (const edge of edges) {
        next[edge[0]].push(edge[1]);
        next[edge[1]].push(edge[0]);
    }

    const count = new Array(n).fill(0);
    const dfs = function (node, parent, end) {
        if (node == end) {
            count[node]++;
            return true;
        }
        for (const child of next[node]) {
            if (child == parent) {
                continue;
            }
            if (dfs(child, node, end)) {
                count[node]++;
                return true;
            }
        }
        return false;
    };

    const dp = function (node, parent) {
        let res = [price[node] * count[node], Math.floor(price[node] * count[node] / 2)];
        for (const child of next[node]) {
            if (child == parent) {
                continue;
            }
            const [x, y] = dp(child, node);
            res[0] += Math.min(x, y); // node 没有减半，因此可以取子树的两种情况的最小值
            res[1] += x; // node 减半，只能取子树没有减半的情况
        }
        return res;
    };

    for (const trip of trips) {
        dfs(trip[0], -1, trip[1]);
    }
    return Math.min(...dp(0, -1));
};



var find = function (uf, i) {
    if (uf[i] == i) {
        return i;
    }
    uf[i] = find(uf, uf[i]);
    return uf[i];
}

var minimumTotalPrice = function (n, edges, price, trips) {
    const next = new Array(n).fill(0).map(() => new Array());
    for (const edge of edges) {
        next[edge[0]].push(edge[1]);
        next[edge[1]].push(edge[0]);
    }

    const query = new Array(n).fill(0).map(() => new Array());
    for (const trip of trips) {
        query[trip[0]].push(trip[1]);
        if (trip[0] != trip[1]) {
            query[trip[1]].push(trip[0]);
        }
    }

    const uf = new Array(n).fill(0);
    const visited = new Array(n).fill(0);
    const diff = new Array(n).fill(0);
    const parent = new Array(n).fill(0);
    const tarjan = function (node, p) {
        parent[node] = p;
        uf[node] = node;
        for (const child of next[node]) {
            if (child == p) {
                continue;
            }
            tarjan(child, node);
            uf[child] = node;
        }
        for (const node1 of query[node]) {
            if (node != node1 && !visited[node1]) {
                continue;
            }
            const lca = find(uf, node1);
            diff[node]++;
            diff[node1]++;
            diff[lca]--;
            if (parent[lca] >= 0) {
                diff[parent[lca]]--;
            }
        }
        visited[node] = 1;
    };
    tarjan(0, -1);

    const count = new Array(n).fill(0);
    const dfs = function (node, p) {
        count[node] = diff[node];
        for (const child of next[node]) {
            if (child == p) {
                continue;
            }
            count[node] += dfs(child, node);
        }
        return count[node];
    };
    dfs(0, -1);

    const dp = function (node, p) {
        let res = [price[node] * count[node], Math.floor(price[node] * count[node] / 2)];
        for (const child of next[node]) {
            if (child == p) {
                continue;
            }
            const [x, y] = dp(child, node);
            res[0] += Math.min(x, y); // node 没有减半，因此可以取子树的两种情况的最小值
            res[1] += x; // node 减半，只能取子树没有减半的情况
        }
        return res;
    };
    return Math.min(...dp(0, -1));
};

