﻿function ListNode(val, next) {
    this.val = (val === undefined ? 0 : val)
    this.next = (next === undefined ? null : next)
}

/**
 * @param {ListNode} list1
 * @param {number} a
 * @param {number} b
 * @param {ListNode} list2
 * @return {ListNode}
 */
var mergeInBetween = function (list1, a, b, list2) {
    let preA = list1;
    for (let i = 0; i < a - 1; i++) {
        preA = preA.next;
    }
    let preB = preA;
    for (let i = 0; i < b - a + 2; i++) {
        preB = preB.next;
    }
    preA.next = list2;
    while (list2.next) {
        list2 = list2.next;
    }
    list2.next = preB;
    return list1;
};
