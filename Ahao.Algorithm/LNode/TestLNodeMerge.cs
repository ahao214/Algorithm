using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.LNode
{
    /// <summary>
    /// 合并两个有序链表
    /// </summary>
    public class TestLNodeMerge
    {
        //方法功能：构造链表
        public static LNode ConstructList(int start)
        {
            int i = start;
            LNode head = new LNode();
            head.next = null;
            LNode tmp = null;
            LNode cur = head;
            for (; i < 7; i += 2)
            {
                tmp = new LNode();
                tmp.data = i;
                tmp.next = null;
                cur.next = tmp;
                cur = tmp;
            }
            return head;
        }

        public static void PrintList(LNode head)
        {
            for (LNode cur = head.next; cur != null; cur = cur.next)
            {
                Console.Write(cur.data + " ");
            }
        }


        /// <summary>
        /// 方法功能：合并两个升序排列的单链表
        /// 输入参数：head1与head2代表两个单链表
        /// 返回值：合并后链表的头结点
        /// </summary>
        /// <param name="head1"></param>
        /// <param name="head2"></param>
        /// <returns></returns>
        public static LNode Merge(LNode head1, LNode head2)
        {
            if (head1 == null || head1.next == null)
            {
                return head2;
            }
            if (head2 == null || head2.next == null)
            {
                return head1;
            }
            LNode cur1 = head1.next;    //用来遍历head1
            LNode cur2 = head2.next;    //用来遍历head2
            LNode head = null;  //合并后链表的头结点
            LNode cur = null;   //合并后的链表在尾结点
            //合并后链表的头结点为第一个结点元素最小的那个链表的头结点
            if (cur1.data > cur2.data)
            {
                head = head2;
                cur = cur2;
                cur2 = cur2.next;
            }
            else
            {
                head = head1;
                cur = cur1;
                cur1 = cur1.next;
            }
            //每次找链表剩余结点的最小值对应的结点连接到合并后链表的尾部
            while (cur1 != null && cur2 != null)
            {
                if (cur1.data < cur2.data)
                {
                    cur.next = cur1;
                    cur = cur1;
                    cur1 = cur1.next;
                }
                else
                {
                    cur.next = cur2;
                    cur = cur2;
                    cur2 = cur2.next;
                }
            }

            //当遍历完一个链表后把另外一个链表剩余的结点链接到合并后的链表后面
            if (cur1 != null)
            {
                cur.next = cur1;
            }
            if (cur2 != null)
            {
                cur.next = cur2;
            }
            return head;

        }

    }
}
