using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 234.回文链表
    /// </summary>
    public class IsPalindromeNum
    {
        public bool Method(ListNodeNum head)
        {
            if (head == null)
            {
                return true;
            }
            if (head.next == null)
            {
                return true;
            }
            ListNodeNum slow = head;
            ListNodeNum fast = head;
            ListNodeNum pre = head;
            ListNodeNum next = null;
            while (fast != null && fast.next != null)
            {
                pre = slow;
                slow = slow.next;
                fast = fast.next.next;
                pre.next = next;
                next = pre;
            }
            if (fast != null)
            {
                slow = slow.next;
            }
            while (pre != null)
            {
                if (slow.val != pre.val)
                {
                    return false;
                }
                pre = pre.next;
                slow = slow.next;
            }
            return true;
        }
    }


    public class ListNodeNum
    {
        public int val;
        public ListNodeNum next;
        public ListNodeNum(int x) { val = x; }
    }

}
