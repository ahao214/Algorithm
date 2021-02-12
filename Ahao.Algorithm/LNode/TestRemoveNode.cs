using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.LNode
{
    /// <summary>
    /// 在只给定单链表中某个结点的指针的情况下删除该结点
    /// </summary>
    public class TestRemoveNode
    {
        public static void PrintList(LNode head)
        {
            for (LNode cur = head.next; cur != null; cur = cur.next)
            {
                Console.Write(cur.data + " ");
            }
        }

        /// <summary>
        /// 方法功能：给定单链表中某个结点，删除该结点
        /// 输入参数：链表中某结点
        /// 返回值：true-删除成功；false-删除失败
        /// </summary>
        /// <param name="p"></param>
        public static bool RemoveNode(LNode p)
        {
            //如果结点为空，或接待p无后续结点则无法删除
            if (p == null || p.next == null)
            {
                return false;
            }
            p.data = p.next.data;
            LNode tmp = p.next;
            p.next = tmp.next;
            return true;
        }
    }
}
