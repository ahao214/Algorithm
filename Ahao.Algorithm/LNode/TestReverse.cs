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


        #region 递归法

        /// <summary>
        /// 方法功能：对不带头结点的单链表进行逆序
        /// 输入参数：firstRef:指向链表第一个结点的指针的指针
        /// </summary>
        /// <param name="head"></param>
        /// <returns></returns>
        private static LNode RecursiveReverse(LNode head)
        {
            //如果链表为空或者链表中只有一个元素
            if (head ==null || head.next == null)
            {
                return head;
            }
            else
            {
                //反转后面的结点
                LNode newhead = RecursiveReverse(head.next);
                //把当前遍历的结点加到后面结点逆序后链表的尾部
                head.next.next = head;
                head.next = null;
                return newhead;
            }
        }

        /// <summary>
        /// 方法功能：对带头结点的单链表进行逆序
        /// 输入参数：head:指向链表头结点指针的指针
        /// </summary>
        /// <param name="head"></param>
        public static void ReverseDG(LNode head)
        {
            if (head ==null )
            {
                return;
            }
            //获取链表第一个结点
            LNode firstNode = head.next;
            //对链表进行逆序
            LNode newhead = RecursiveReverse(firstNode);
            //头结点指向逆序后链表的第一个结点
            head.next = newhead;
        }

        #endregion


        #region 插入法
        /// <summary>
        /// 主要思路：从链表的第二个结点开始，把遍历到的结点插入到头结点的后面，直到遍历结束
        /// </summary>
        /// <param name="head"></param>
        public static void ReverseInsert(LNode head)
        {
            //判断链表是否为空
            if (head ==null || head.next ==null)
            {
                return;
            }
            LNode cur = null;   //当前结点
            LNode next = null;  //后续结点
            cur = head.next.next;
            //设置链表第一个结点为尾结点
            head.next.next = null;
            //把遍历到结点插入到头结点的后面
            while (cur!=null)
            {
                next = cur.next;
                cur.next = head.next;
                head.next = cur;
                cur = next;
            }

        }

        #endregion

    }

    //public class LNode
    //{
    //    public int data;   //数据域
    //    public LNode next; //下一个结点的引用
    //}

}
