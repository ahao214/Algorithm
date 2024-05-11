using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Nowcoder.Easy.JZ22
{
    /// <summary>
    /// JZ22 链表中倒数最后k个结点
    /// </summary>
    public class Class22
    {
        public ListNode FindKthToTail(ListNode head, int k)
        {
            ListNode pre = head;
            int len = 0;
            while (pre != null)
            {
                len++;
                pre = pre.next;
            }
            len -= k;
            while (len > 0)
            {
                len--;
                head = head.next;
            }
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
