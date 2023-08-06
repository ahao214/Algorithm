
class ListNode {
    val: number
    next: ListNode | null
    constructor(val?: number, next?: ListNode | null) {
        this.val = (val === undefined ? 0 : val)
        this.next = (next === undefined ? null : next)
    }
}


function addTwoNumbers(l1: ListNode | null, l2: ListNode | null): ListNode | null {
    const newList = new ListNode(0);
    let cur = newList;
    let curry = 0;
    while (l1 || l2) {
        const val1 = l1?.val ?? 0;
        const val2 = l2?.val ?? 0;
        const val = val1 + val2 + curry;
        curry = Math.floor(val / 10);
        cur.next = new ListNode(val % 10);
        if (l1) {
            l1 = l1.next;
        }
        if (l2) {
            l2 = l2.next;
        }
        cur = cur.next;
    }
    if (curry) {
        cur.next = new ListNode(curry);
    }
    return newList.next;
};