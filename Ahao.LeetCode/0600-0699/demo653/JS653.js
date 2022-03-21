function TreeNode(val, left, right) {
    this.val = (val === undefined ? 0 : val)
    this.left = (left === undefined ? null : left)
    this.right = (right === undefined ? null : right)
}

/**
 * @param {TreeNode} root
 * @param {number} k
 * @return {boolean}
 */

//深度优先+哈希表
var findTarget = function (root, k) {
    const set = new Set();
    const helper = (root, k) => {
        if (!root) {
            return fasle;
        }
        if (set.has(k - root.val)) {
            return true;
        }
        set.add(root.val);
        return helper(root.left, k) || helper(root.right, k);
    }
    return helper(root, k);
};


//广度优先+哈希表
var findTarget1 = function (root, k) {
    const set = new Set();
    const q = [];
    q.push(root);
    while (q.length) {
        const node = q.shift();
        if (set.has(k - node.val)) {
            return true;
        }
        set.add(node.val);
        if (node.left) {
            q.push(node.left);
        }
        if (node.right) {
            q.push(node.right);
        }
    }
    return false;
};