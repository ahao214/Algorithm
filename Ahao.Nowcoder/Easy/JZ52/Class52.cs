using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Nowcoder.Easy.JZ52
{
    /// <summary>
    /// JZ52 两个链表的第一个公共结点
    /// </summary>
    public class Class52
    {
        public ListNode FindFirstCommonNode(ListNode pHead1, ListNode pHead2)
        {
            ListNode slow = pHead1;
            ListNode fast = pHead2;
            while (slow != fast)
            {
                if (slow == null)
                {
                    slow = pHead2;
                }
                else
                {
                    slow = slow.next;
                }

                if (fast == null)
                {
                    fast = pHead1;
                }
                else
                {
                    fast = fast.next;
                }
            }
            return fast;
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
