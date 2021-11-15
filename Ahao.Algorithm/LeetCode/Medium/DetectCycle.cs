using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Web.Security;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 142.环形链表(2)
    /// </summary>
    public class DetectCycle
    {
        public ListNode Method(ListNode head)
        {
            ListNode fast = head;
            ListNode slow = head;
            bool IsDetectCycle = false;
            if (head == null || head.next == null)
            {
                return null;
            }
            while (fast != null && fast.next != null)
            {
                fast = fast.next.next;
                slow = slow.next;
                if (fast == slow)
                {
                    IsDetectCycle = true;
                    break;
                }
            }

            if (IsDetectCycle)
            {
                slow = head;
                while (fast != slow)
                {
                    fast = fast.next;
                    slow = slow.next;
                }
                return fast;
            }
            else
            {
                return null;
            }
        }


        public ListNode Method1(ListNode head)
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
            {
                return null;
            }
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
