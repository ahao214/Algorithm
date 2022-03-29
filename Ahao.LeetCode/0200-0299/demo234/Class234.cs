using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0200_0299.demo234
{
    public class Class234
    {
        public bool IsPalindrome(ListNode head)
        {
            if (head == null || head.next == null)
                return true;
            if (head.next.next == null)
                return head.val == head.next.val;

            ListNode mid = getMidNode(head);
            ListNode rightHead = reverseList(mid.next);
            ListNode leftHead = head;
            while (rightHead != null)
            {
                if (rightHead.val != leftHead.val)
                    return false;                
                rightHead = rightHead.next;
                leftHead = leftHead.next;
            }
            return true;
        }

        private ListNode getMidNode(ListNode head)
        {
            ListNode fast = head, slow = head;
            while (fast.next != null && fast.next.next != null)
            {
                slow = slow.next;
                fast = fast.next.next;
            }
            return slow;
        }

        private ListNode reverseList(ListNode head)
        {
            ListNode newHead = null;
            while (head != null)
            {
                ListNode tmp = head.next;
                head.next = newHead;
                newHead = head;
                head = tmp;
            }
            return newHead;
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
