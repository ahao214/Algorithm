
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


function addTwoNumbers2(l1: ListNode | null, l2: ListNode | null,): ListNode | null {
    const dummy = new ListNode();
    let cur = dummy;
    let sum = 0;
    while (sum !== 0 || l1 !== null || l2 !== null) {
        if (l1 != null) {
            sum += l1.val;
            l1 = l1.next;
        }
        if (l2 != null) {
            sum += l2.val;
            l2 = l2.next;
        }
        cur.next = new ListNode(sum % 10);
        cur = cur.next;
        sum = Math.floor(sum / 10);
    }
    return dummy.next;
}