function ListNode(val, next) {
    this.val = (val === undefined ? 0 : val)
    this.next = (next === undefined ? null : next)
}

/**
 * @param {ListNode} head
 * @param {number[]} nums
 * @return {number}
 */
var numComponents = function (head, nums) {
    const numsSet = new Set();
    for (const num of nums) {
        numsSet.add(num);
    }
    let inSet = false;
    let res = 0;
    while (head) {
        if (numsSet.has(head.val)) {
            if (!inSet) {
                inSet = true;
                res++;
            }
        } else {
            inSet = false;
        }
        head = head.next;
    }
    return res;
};

