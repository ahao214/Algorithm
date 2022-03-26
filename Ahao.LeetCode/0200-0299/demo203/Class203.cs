using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0200_0299.demo203
{
    public class Class203
    {
        public ListNode RemoveElements(ListNode head, int val)
        {
            if (head == null)
                return null;
            ListNode newHead = null;
            ListNode newTail = null;
            while (head != null)
            {
                if (head.val != val)
                {
                    if (newTail == null)
                    {
                        newHead = head;
                        newTail = head;
                    }
                    else
                    {
                        newTail.next = head;
                        newTail = head;
                    }
                }
                head = head.next;
            }
            if (newTail == null)
            {
                return null;
            }
            else
            {
                newTail.next = null;
            }
            return newHead;
        }

        public ListNode RemoveElements2(ListNode head, int val)
        {
            if (head == null)
                return null;
            ListNode newHead = new ListNode(0);
            ListNode newTail = newHead;
            while (head != null)
            {
                if (head.val != val)
                {
                    newTail.next = head;
                    newTail = head;
                }
                head = head.next;
            }
            newTail.next = null;
            return newHead.next;
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
