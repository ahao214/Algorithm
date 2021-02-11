using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.LNode
{
    /// <summary>
    /// 把链表相邻元素翻转
    /// </summary>
    public class TestReverseN
    {
        //把链表相邻元素翻转
        public static void Reverse(LNode head)
        {
            if (head ==null || head.next ==null )
            {
                return;
            }
            //当前遍历结点
            LNode cur = head.next;
            //当前结点的前驱结点
            LNode pre = head;
            //当前结点后续结点的后续结点
            LNode next = null;
            while(cur!=null && cur .next !=null )
            {
                next = cur.next.next;
                pre.next = cur.next;
                cur.next.next = cur;
                cur.next = next;
                pre = cur;
                cur = next;
            }
        }
    }
}
