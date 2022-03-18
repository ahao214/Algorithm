using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo61
{
    /*
     61. 旋转链表
给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。
     */
    public class Class61
    {
        public ListNode RotateRight(ListNode head, int k)
        {
            if (head == null)
                return head;
            var dummy = new ListNode(0) { next = head };
            var n = 0;
            var p = head;
            while (true)
            {
                n++;
                if (p.next == null)
                {
                    p.next = head;
                    break;
                }
                p = p.next;
            }
            k = n - k % n;
            if (k == 0)
                return head;
            p = dummy;
            while (k > 0)
            {
                k--;
                p = p.next;
            }
            head = p.next;
            p.next = null;
            return head;
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
