using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Runtime.InteropServices.WindowsRuntime;
using System.Text;
using System.Threading.Tasks;
using System.Web;

namespace Ahao.Algorithm.LNode
{
    /// <summary>
    /// 把链表以K个结点为一组进行翻转
    /// </summary>
    public class TestReverseByK
    {
        //对不带头结点的单链表翻转
        private static LNode Reverse(LNode head)
        {
            if (head == null || head.next == null)
            {
                return head;
            }

            LNode pre = head;   //前驱结点
            LNode cur = head.next;  //当前结点
            LNode next = cur.next;  //后续结点
            pre.next = null;

            //使当前遍历到的结点cur指向其前驱结点
            while (cur != null)
            {
                next = cur.next;
                cur.next = pre;
                pre = cur;
                cur = cur.next;
                cur = next;
            }
            return pre;
        }


        //对链表K翻转
        public static void ReverseK(LNode head, int k)
        {
            if (head == null || head.next == null)
            {
                return;
            }

            int i = 1;
            LNode pre = head;
            LNode begin = head.next;
            LNode end = null;
            LNode pNext = null;
            while (begin != null)
            {
                end = begin;
                //找到从begin开始第K个结点
                for (; i < k; i++)
                {
                    if (end.next != null)
                    {
                        end = end.next;
                    }
                    else
                    {
                        //剩余结点的个数小于K
                        return;
                    }
                }
                pNext = end.next;
                end.next = null;
                pre.next = Reverse(begin);
                begin.next = pNext;
                pre = begin;
                begin = pNext;
                i = 1;
            }
        }
    }
}
