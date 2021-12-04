using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo2
{
    /// <summary>
    /// 2. 两数相加
    /// 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
    ///请你将两个数相加，并以相同形式返回一个表示和的链表。
    ///你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
    /// </summary>
    public class Class2
    {
        public ListNode AddTwoNumbers(ListNode l1, ListNode l2)
        {
            var node1 = l1;
            var node2 = l2;
            var c = 0;
            var dummy = new ListNode(0);
            var tail = dummy;
            while (node1 != null | node2 != null)
            {
                var nOne = node1?.val ?? 0;
                var nTwo = node2?.val ?? 0;
                var n = nOne + nTwo + c;
                tail = tail.next = new ListNode(n % 10);
                c = n / 10;
                node1 = node1?.next;
                node2 = node2?.next;
            }
            if (c != 0)
            {
                tail = tail.next = new ListNode(c);
            }
            return dummy.next;

        }
    }

    public class ListNode
    {
        public int val;
        public ListNode next;
        public ListNode(int val = 0, ListNode next = null)
        {
            this.val = val;
            this.next = next;
        }
    }
}
