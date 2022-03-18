using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo82
{
    /*
     82. 删除排序链表中的重复元素 II
给定一个已排序的链表的头 head ， 删除原始链表中所有重复数字的节点，只留下不同的数字 。返回 已排序的链表 。
     */
    public class Class82
    {
        public ListNode DeleteDuplicates(ListNode head)
        {
            if (head == null)
                return null;
            var dummy = new ListNode(0) { next = head };
            var pre = dummy;
            var cur = pre.next;
            while (cur != null)
            {
                if (cur.next != null && cur.val == cur.next.val)
                {
                    var node = cur.next.next;
                    while (node != null && cur.val == node.val)
                        node = node.next;
                    pre.next = cur = node;
                }
                else
                {
                    pre = cur;
                    cur = cur.next;
                }
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
