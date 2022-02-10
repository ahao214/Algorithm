using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Hard.demo25
{
    /*
     25. K 个一组翻转链表
    给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
    k是一个正整数，它的值小于或等于链表的长度。
    如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
    */
    public class Class25
    {
        public ListNode ReverseKGroup(ListNode head, int k)
        {
            var stack = new Stack<ListNode>(k);
            var dummy = new ListNode(0) { next = head };
            var p = dummy;
            var q = dummy;
            for (int i = 0; i < k; i++)
            {
                q = q?.next;
            }
            while (q != null)
            {
                var h = p.next;
                var t = q.next;
                while (h != t)
                {
                    stack.Push(h);
                    h = h.next;
                }
                while (stack.Count > 0)
                {
                    p = p.next = stack.Pop();
                }
                p.next = t;
                q = p;
                for (int i = 0; i < k; i++)
                {
                    q = q?.next;
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
