function TreeNode(val, left, right) {
    this.val = (val === undefined ? 0 : val)
    this.left = (left === undefined ? null : left)
    this.right = (right === undefined ? null : right)
}



let move;

var distributeCoins = function (root) {
    move = 0;
    dfs(root);
    return move;
};

function dfs(root) {
    let moveleft = 0;
    let moveright = 0;
    if (root === null) {
        return 0;
    }
    if (root.left !== null) {
        moveleft = dfs(root.left);
    }
    if (root.right !== null) {
        moveright = dfs(root.right);
    }
    move += Math.abs(moveleft) + Math.abs(moveright);
    return moveleft + moveright + root.val - 1;
}
