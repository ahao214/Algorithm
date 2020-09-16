using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm
{
    /// <summary>
    /// 83.删除排序链表中的重复元素
    /// </summary>
    public class DeleteDuplicates
    {
        public ListNode Method(ListNode head)
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


}
