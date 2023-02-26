using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Hard.demo25
{
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
