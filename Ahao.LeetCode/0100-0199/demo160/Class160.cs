using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0100_0199.demo160
{
    public class Class160
    {
        public ListNode GetIntersectionNode(ListNode headA, ListNode headB)
        {
            /*
             把A链表复制一份到B链表后面
             把B链表复制一份到A链表后面
             */
            if (headA == null || headB == null)
                return null;
            ListNode curA = headA, curB = headB;
            while (curA != curB)
            {
                curA = curA == null ? headB : curA.next;
                curB = curB == null ? headA : curB.next;
            }
            return curA;
        }
    }

    public class ListNode
    {
        public int val;
        public ListNode next;
        public ListNode(int x)
        {
            val = x;
        }
    }

}
