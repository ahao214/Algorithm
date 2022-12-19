//广度优先
var validPath = function (n, edges, source, destination) {
    const adj = new Array(n).fill(0).map(() => new Array());
    for (const edge of edges) {
        const x = edge[0], y = edge[1];
        adj[x].push(y);
        adj[y].push(x);
    }
    const visited = new Array(n).fill(false);
    const queue = [source];
    visited[source] = true;
    while (queue.length) {
        const vertex = queue.shift();
        if (vertex === destination) {
            break;
        }
        for (const next of adj[vertex]) {
            if (!visited[next]) {
                queue.push(next);
                visited[next] = true;
            }
        }
    }
    return visited[destination];
};

//深度优先
var validPath = function (n, edges, source, destination) {
    const adj = new Array(n).fill(0).map(() => new Array());
    for (const edge of edges) {
        const x = edge[0], y = edge[1];
        adj[x].push(y);
        adj[y].push(x);
    }
    const visited = new Array(n).fill(0);
    return dfs(source, destination, adj, visited);
}

const dfs = (source, destination, adj, visited) => {
    if (source === destination) {
        return true;
    }
    visited[source] = true;
    for (const next of adj[source]) {
        if (!visited[next] && dfs(next, destination, adj, visited)) {
            return true;
        }
    }
    return false;
};
