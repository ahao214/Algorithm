//广度优先
var findMinHeightTrees = function (n, edges) {
    const ans = [];
    if (n === 1) {
        ans.push(0);
        return ans;
    }
    const adj = new Array(n).fill(0).map(() => new Array());
    for (const edge of edges) {
        adj[edge[0]].push(edge[1]);
        adj[edge[1]].push(edge[0]);
    }

    const parent = new Array(n).fill(-1);
    /* 找到与节点 0 最远的节点 x */
    const x = findLongestNode(0, parent, adj);
    /* 找到与节点 x 最远的节点 y */
    let y = findLongestNode(x, parent, adj);
    /* 求出节点 x 到节点 y 的路径 */
    const path = [];
    parent[x] = -1;
    while (y !== -1) {
        path.push(y);
        y = parent[y];
    }
    const m = path.length;
    if (m % 2 === 0) {
        ans.push(path[Math.floor(m / 2) - 1]);
    }
    ans.push(path[Math.floor(m / 2)]);
    return ans;
}

const findLongestNode = (u, parent, adj) => {
    const n = adj.length;
    const queue = [];
    const visit = new Array(n).fill(false);
    queue.push(u);
    visit[u] = true;
    let node = -1;

    while (queue.length) {
        const curr = queue.shift();
        node = curr;
        for (const v of adj[curr]) {
            if (!visit[v]) {
                visit[v] = true;
                parent[v] = curr;
                queue.push(v);
            }
        }
    }
    return node;
};


//拓扑排序
var findMinHeightTrees2 = function (n, edges) {
    const ans = [];
    if (n === 1) {
        ans.push(0);
        return ans;
    }
    const degree = new Array(n).fill(0);
    const adj = new Array(n).fill(0).map(() => new Array());
    for (const edge of edges) {
        adj[edge[0]].push(edge[1]);
        adj[edge[1]].push(edge[0]);
        degree[edge[0]]++;
        degree[edge[1]]++;
    }
    const queue = [];
    for (let i = 0; i < n; i++) {
        if (degree[i] === 1) {
            queue.push(i);
        }
    }
    let remainNodes = n;
    while (remainNodes > 2) {
        const sz = queue.length;
        remainNodes -= sz;
        for (let i = 0; i < sz; i++) {
            const curr = queue.shift();
            for (const v of adj[curr]) {
                degree[v]--;
                if (degree[v] === 1) {
                    queue.push(v);
                }
            }
        }
    }
    while (queue.length) {
        ans.push(queue.shift());
    }
    return ans;
};
