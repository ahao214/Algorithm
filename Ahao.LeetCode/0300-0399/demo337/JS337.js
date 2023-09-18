var rob = function(root) {
    const dfs = (node) => {
        if (node === null) {
            return [0, 0];
        }
        const l = dfs(node.left);
        const r = dfs(node.right);
        const selected = node.val + l[1] + r[1];
        const notSelected = Math.max(l[0], l[1]) + Math.max(r[0], r[1]);
        return [selected, notSelected];
    }
    
    const rootStatus = dfs(root);
    return Math.max(rootStatus[0], rootStatus[1]);
}; 



var rob = function(root) {
    const f = new Map();
    const g = new Map();

    const dfs = (node) => {
        if (node === null) {
            return;
        }
        dfs(node.left);
        dfs(node.right);
        f.set(node, node.val + (g.get(node.left) || 0) + (g.get(node.right) || 0));
        g.set(node, Math.max(f.get(node.left) || 0, g.get(node.left) || 0) + Math.max(f.get(node.right) || 0, g.get(node.right) || 0));
    }
    
    dfs(root);
    return Math.max(f.get(root) || 0, g.get(root) || 0);
};
