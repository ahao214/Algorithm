using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 203.移除链表元素
    /// </summary>
    public class RemoveElements
    {
        public ListNodes Method(ListNodes head,int val)
        {
            if (head == null)
                return head;
            head.next = Method(head.next, val);
            return head.val == val ? head.next : head;
        }

    }

    public class ListNodes
    {
        public int val;
        public ListNodes next;
        public ListNodes(int val = 0, ListNodes next = null)
        {
            this.val = val;
            this.next = next;
        }
    }

}
