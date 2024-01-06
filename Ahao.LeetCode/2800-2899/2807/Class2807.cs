using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2800_2899._2807
{
    public class Class2807
    {
        public ListNode InsertGreatestCommonDivisors(ListNode head)
        {
            ListNode node = head;
            while (node.next != null)
            {
                node.next = new ListNode(GCD(node.val, node.next.val), node.next);
                node = node.next.next;
            }
            return head;
        }

        public int GCD(int a, int b)
        {
            while (b != 0)
            {
                int tmp = a % b;
                a = b;
                b = tmp;
            }
            return a;
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
