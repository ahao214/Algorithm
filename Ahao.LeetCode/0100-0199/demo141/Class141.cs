using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0100_0199.demo141
{
    public class Class146
    {
        public bool HasCycle(ListNode head)
        {
            //使用快慢指针
            ListNode fast = head;
            ListNode slow = head;
            if (head == null || head.next == null)
            {
                return false;
            }
            while (fast != null && fast.next != null)
            {
                fast = fast.next.next;
                slow = slow.next;
                if (fast == slow)
                {
                    return true;
                }
            }
            return false;
        }

        public bool HasCycle2(ListNode head)
        {
            ISet<ListNode> st = new HashSet<ListNode>();
            while (head != null)
            {
                if (!st.Add(head))
                {
                    return true;
                }
                head = head.next;
            }
            return false;
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
