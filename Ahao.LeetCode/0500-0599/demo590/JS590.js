//递归
var postorder = function (root) {
    const res = [];
    helper(root, res);
    return res;
}

const helper = (root, res) => {
    if (root == null) {
        return;
    }
    for (const ch of root.children) {
        helper(ch, res);
    }
    res.push(root.val);
};

//迭代
var postorder1 = function (root) {
    const res = [];
    if (root == null) {
        return res;
    }
    const map = new Map();
    const stack = [];
    let node = root;
    while (stack.length || node) {
        while (node) {
            stack.push(node);
            const children = node.children;
            if (children && children.length > 0) {
                map.set(node, 0);
                node = children[0];
            } else {
                node = null;
            }
        }
        node = stack[stack.length - 1];
        const index = (map.get(node) || 0) + 1;
        const children = node.children;
        if (children && children.length > index) {
            map.set(node, index);
            node = children[index];
        } else {
            res.push(node.val);
            stack.pop();
            map.delete(node);
            node = null;
        }
    }
    return res;
};


//迭代优化
var postorder2 = function (root) {
    const res = [];
    if (root == null) {
        return res;
    }

    const stack = [];
    const visited = new Set();
    stack.push(root);
    while (stack.length) {
        const node = stack[stack.length - 1];
        /* 如果当前节点为叶子节点或者当前节点的子节点已经遍历过 */
        if (node.children.length === 0 || visited.has(node)) {
            stack.pop();
            res.push(node.val);
            continue;
        }
        for (let i = node.children.length - 1; i >= 0; --i) {
            stack.push(node.children[i]);
        }
        visited.add(node);
    }
    return res;
};