using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Nowcoder.Easy.NC25
{
    /// <summary>
    /// NC25 删除有序链表中重复的元素-1
    /// </summary>
    public class Class25
    {
        public ListNode deleteDuplicates(ListNode head)
        {
            if (head == null)
            {
                return null;
            }
            var result = head;
            var next = head.next;
            while (head != null && next != null)
            {
                if (next.val != head.val)
                {
                    head = head.next;
                    next = head.next;
                }
                else
                {
                    next = next.next;
                    head.next = next;
                }
            }
            return result;
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
