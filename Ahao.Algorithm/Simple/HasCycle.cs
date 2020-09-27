using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Web.Configuration;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 141.环形链表
    /// </summary>
    public class HasCycle
    {
        public bool Method(ListNode head)
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
