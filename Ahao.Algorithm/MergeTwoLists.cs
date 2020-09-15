using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm
{
    /// <summary>
    /// 21. 合并两个有序链表
    /// </summary>
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

    public class MergeTwoLists
    {
        public ListNode Method(ListNode l1, ListNode l2)
        {           
            //递归
            if (l1 == null || l2 == null)
            {
                return l1 == null ? l2 : l1;
            }
            if (l1.val < l2.val)
            {
                l1.next = Method(l1.next, l2);
                return l1;
            }
            else
            {
                l2.next = Method(l2.next, l1);
                return l2;
            }
        }
    }
}
