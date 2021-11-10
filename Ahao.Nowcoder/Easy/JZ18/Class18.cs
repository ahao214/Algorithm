using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Nowcoder.Easy.JZ18
{
    /// <summary>
    /// JZ18 删除链表的节点
    /// </summary>
    public class Class18
    {
        public ListNode deleteNode(ListNode head, int val)
        {
            if (head.val == val)
            {
                return head.next;
            }
            ListNode pre = new ListNode(0);
            pre.next = head;
            ListNode cur = head;
            ListNode next = null;
            while (cur != null)
            {
                cur = cur.next;
                pre = pre.next;
                if (cur.val == val)
                {
                    next = cur.next;
                    break;
                }
            }
            cur.next = null;
            pre.next = next;
            return head;
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
