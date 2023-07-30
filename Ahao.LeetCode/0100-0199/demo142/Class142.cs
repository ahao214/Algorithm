using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0100_0199.demo142
{
    internal class Class142
    {
        public ListNode DetectCycle(ListNode head)
        {
            var p1 = head;
            var p2 = head;
            while (p2 != null)
            {
                p1 = p1.next;
                p2 = p2.next?.next;
                if (p1 == p2)
                    break;
            }
            if (p2 == null)
                return null;

            var node = head;
            while (node != p1)
            {
                node = node.next;
                p1 = p1.next;
            }
            return node;
        }
    }


    public class ListNode
    {
        public int val;
        public ListNode next;
        public ListNode(int x)
        {
            val = x;
            next = null;
        }
    }
}
