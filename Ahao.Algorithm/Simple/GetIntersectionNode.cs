using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 剑指 Offer 52. 两个链表的第一个公共节点
    /// </summary>
    public class GetIntersectionNode
    {
        public ListNodeG Method(ListNodeG headA, ListNodeG headB)
        {
            ISet<ListNodeG> visited = new HashSet<ListNodeG>();
            ListNodeG temp = headA;
            while (temp != null)
            {
                visited.Add(temp);
                temp = temp.next;
            }
            temp = headB;
            while (temp != null)
            {
                if (visited.Contains(temp))
                {
                    return temp;
                }
                temp = temp.next;
            }
            return null;
        }
    }


    public class ListNodeG
    {
        public int val;
        public ListNodeG next;
        public ListNodeG(int x) { val = x; }
    }

}
