using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 剑指 Offer 22. 链表中倒数第k个节点
    /// </summary>
    public class GetKthFromEnd
    {
        public ListNodeK Method(ListNodeK head, int k)
        {
            ListNodeK pre = head;
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

    public class ListNodeK
    {
        public int val;
        public ListNodeK next;
        public ListNodeK(int x) { val = x; }
    }


}
