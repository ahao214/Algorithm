using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.LNode
{
    /// <summary>
    /// 判断两个链表是否相交
    /// </summary>
    public class TestIsIntersect
    {
        /// <summary>
        /// 方法功能：判断两个链表是否相交，如果相交找出交点
        /// 输入参数：head1与head2分别为两个链表的头结点
        /// 返回值：如果不相交返回null，如果相交返回相交结点
        /// </summary>
        /// <param name="head1"></param>
        /// <param name="head2"></param>
        /// <returns></returns>
        public static LNode IsIntersect(LNode head1, LNode head2)
        {
            if (head1 == null || head1.next == null || head2 == null || head2.next == null || head1 == head2)
            {
                return null;
            }
            LNode temp1 = head1.next;
            LNode temp2 = head2.next;
            int n1 = 0, n2 = 0;
            //遍历head1，找到尾结点，同时记录head1的长度
            while (temp1.next != null)
            {
                temp1 = temp1.next;
                ++n1;
            }
            //遍历head2，找到尾结点，同时记录head2的长度
            while (temp2.next != null)
            {
                temp2 = temp2.next;
                ++n2;
            }
            //head1与head2是有相同的尾结点
            if (temp1 == temp2)
            {
                //长链表先走n1-n2步
                if (n1 > n2)
                {
                    while (n1 - n2 > 0)
                    {
                        head1 = head1.next;
                        --n1;
                    }
                }
                if (n2 > n1)
                {
                    while (n2 - n1 > 0)
                    {
                        head2 = head2.next;
                        --n2;
                    }
                }
                //两个链表同时前进，找出相同的结点
                while (head1 != head2)
                {
                    head1 = head1.next;
                    head2 = head2.next;
                }
                return head1;
            }
            //head1与head2没有相同尾结点
            return null;
        }
    }
}
