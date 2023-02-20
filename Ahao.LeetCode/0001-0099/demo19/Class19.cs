using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo19
{
    public class Class19
    {
        public ListNode RemoveNthFromEnd(ListNode head, int n)
        {
            var dummy = new ListNode(0) { next = head };
            var p = dummy;
            var q = p.next;
            for (int i = 0; i < n; i++)
            {
                q = q.next;
            }
            while (q != null)
            {
                p = p.next;
                q = q.next;
            }
            p.next = p.next.next;
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
