﻿function ListNode(val, next) {
    this.val = (val === undefined ? 0 : val)
    this.next = (next === undefined ? null : next)
}



var removeZeroSumSublists = function (head) {
    let dummy = new ListNode(0);
    dummy.next = head;
    let seen = {};
    let prefix = 0;
    for (let node = dummy; node !== null; node = node.next) {
        prefix += node.val;
        seen[prefix] = node;
    }
    prefix = 0;
    for (let node = dummy; node !== null; node = node.next) {
        prefix += node.val;
        node.next = seen[prefix].next;
    }
    return dummy.next;
};

