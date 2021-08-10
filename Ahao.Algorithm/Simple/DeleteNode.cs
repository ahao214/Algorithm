using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 237. 删除链表中的节点
    /// </summary>
    public class DeleteNode
    {
        public void Method(ListDeleteNode node)
        {
            node.val = node.next.val;
            node.next = node.next.next;
        }
    }

    public class ListDeleteNode
    {
        public int val;
        public ListDeleteNode next;
        public ListDeleteNode(int x) { val = x; }
    }


}
