function ListNode(val, next) {
    this.val = (val === undefined ? 0 : val)
    this.next = (next === undefined ? null : next)
}



let gcd = (a, b) => b == 0 ? a : gcd(b, a % b)

var insertGreatestCommonDivisors = function (head) {
    let node = head
    while (node.next != null) {
        node.next = new ListNode(gcd(node.val, node.next.val), node.next);
        node = node.next.next;
    }
    return head;
};

