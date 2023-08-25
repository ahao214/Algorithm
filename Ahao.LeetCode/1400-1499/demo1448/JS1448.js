function TreeNode(val, left, right) {
    this.val = (val === undefined ? 0 : val)
    this.left = (left === undefined ? null : left)
    this.right = (right === undefined ? null : right)
}


var goodNodes = function (root) {
    const dfs = (root, path_max) => {
        if (root == null) {
            return 0;
        }
        let res = 0;
        if (root.val >= path_max) {
            res++;
            path_max = root.val;
        }
        res += dfs(root.left, path_max) + dfs(root.right, path_max);
        return res;
    }
    return dfs(root, -Infinity);
};
