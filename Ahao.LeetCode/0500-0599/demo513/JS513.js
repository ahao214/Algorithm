//深度优先搜索

function TreeNode(val, left, right) {
    this.val = (val === undefined ? 0 : val)
    this.left = (left === undefined ? null : left)
    this.right = (right === undefined ? null : right)
}

var findBottomLeftValue = function (root) {
    const dfs = (root, height) => {
        if (!root) {
            return;
        }
        height++;
        dfs(root.left, height);
        dfs(root.right, height);
        if (height > curHeight) {
            curHeight = height;
            curVal = root.val;
        }
    }

    let curHeight = 0;
    dfs(root, 0);
    return curVal;
};



//广度优先搜索
var findBottomLeftValue = function (root) {
    let ret = 0;
    const queue = [root];
    while (queue.length) {
        const p = queue.shift();
        if (p.right) {
            queue.push(p.right);
        }
        if (p.left) {
            queue.push(p.left);
        }
        ret = p.val;
    }
    return ret;
};