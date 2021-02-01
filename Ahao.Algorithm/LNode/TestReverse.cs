using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.LNode
{
    /// <summary>
    /// 如何实现链表的逆序
    /// </summary>
    public class TestReverse
    {
        /// <summary>
        /// 方法功能：对单链表进行逆序 输入参数：head:指向链表头结点的引用
        /// 就地逆序
        /// </summary>
        /// <param name="head"></param>
        public static void Reverse(LNode head)
        {
            //判断是否为空
            if (head == null || head.next == null)
            {
                return;
            }
            LNode pre = null;   //前驱结点
            LNode cur = null;   //当前结点
            LNode next = null;  //后续结点
            //把链表首结点变成尾结点
            cur = head.next;
            next = cur.next;
            cur.next = null;
            pre = cur;
            cur = next;
            //使当前遍历到的结点cur指向其前驱结点
            while (cur.next != null)
            {
                next = cur.next;
                cur.next = pre;
                pre = cur;
                cur = next;
            }
            //结点最后一个结点指向倒数第二个结点
            cur.next = pre;
            //链表的头结点指向原来链表的尾结点
            head.next = cur;
        }
    }

    public class LNode
    {
        public int data;   //数据域
        public LNode next; //下一个结点的引用
    }

}
