using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Nowcoder.LessHard.JZ76
{
    /// <summary>
    /// JZ76 删除链表中重复的结点
    /// </summary>
    public class Class76
    {
        public ListNode deleteDuplication(ListNode pHead)
        {
            //双指针法
            ListNode preHead = new ListNode(-1);
            preHead.next = pHead;

            ListNode pre = preHead;
            while (pre.next != null)
            {
                ListNode curr = pre.next;
                while (curr != null && pre.next.val == curr.val)
                    curr = curr.next;

                //不删除的情况，curr处的节点无重复，即该段节点只有一个
                if (pre.next.next == curr)
                {
                    pre = pre.next;
                }
                else
                {
                    pre.next = curr;
                }
            }
            return preHead.next;
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
