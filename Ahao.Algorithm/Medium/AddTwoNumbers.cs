using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 2.两数相加
    /// </summary>
    public class AddTwoNumbers
    {
        public ListNode Method(ListNode l1, ListNode l2)
        {
            ListNode result = new ListNode(0);
            var preNode = result;
            int val = 0;
            while (l1 != null || l2 != null)
            {
                val = (l1 == null ? 0 : l1.val) + (l2 == null ? 0 : l2.val) + val;

                preNode.next = new ListNode(val % 10);
                preNode = preNode.next;
                val = val / 10;
                l1 = l1?.next;
                l2 = l2?.next;
            }
            if (val != 0)
            {
                preNode.next = new ListNode(val);
            }
            return result.next;
        }
    }



    //public class ListNode
    //{
    //    public int val;
    //    public ListNode next;
    //    public ListNode(int x) { val = x; }
    //}
}
