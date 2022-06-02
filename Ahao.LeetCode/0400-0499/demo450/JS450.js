function TreeNode(val, left, right) {
  this.val = (val === undefined ? 0 : val)
         this.left = (left === undefined ? null : left)
            this.right = (right === undefined ? null : right)
                 }

//方法一：递归
var deleteNode = function (root, key) {
    if (!root) {
        return null;
    }
    if (root.val > key) {
        root.left = deleteNode(root.left, key);
        return root;
    }
    if (root.val < key) {
        root.right = deleteNode(root.right, key);
        return root;
    }
    if (root.val === key) {
        if (!root.left && !root.right) {
            return null;
        }
        if (!root.right) {
            return root.left;
        }
        if (!root.left) {
            return root.right;
        }
        let successor = root.right;
        while (successor.left) {
            successor = successor.left;
        }
        root.right = deleteNode(root.right, successor.val);
        successor.right = root.right;
        successor.left = root.left;
        return successor;
    }
    return root;
};


//方法二：迭代
var deleteNode = function (root, key) {
    let cur = root, curParent = null;
    while (cur && cur.val !== key) {
        curParent = cur;
        if (cur.val > key) {
            cur = cur.left;
        } else {
            cur = cur.right;
        }
    }
    if (!cur) {
        return root;
    }
    if (!cur.left && !cur.right) {
        cur = null;
    } else if (!cur.right) {
        cur = cur.left;
    } else if (!cur.left) {
        cur = cur.right;
    } else {
        let successor = cur.right, successorParent = cur;
        while (successor.left) {
            successorParent = successor;
            successor = successor.left;
        }
        if (successorParent.val === cur.val) {
            successorParent.right = successor.right;
        } else {
            successorParent.left = successor.right;
        }
        successor.right = cur.right;
        successor.left = cur.left;
        cur = successor;
    }
    if (!curParent) {
        return cur;
    } else {
        if (curParent.left && curParent.left.val === key) {
            curParent.left = cur;
        } else {
            curParent.right = cur;
        }
        return root;
    }
};
