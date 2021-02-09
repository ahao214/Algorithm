using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.LNode
{
    /// <summary>
    /// 将单链表向右旋转K个位置
    /// </summary>
    public class TestRotateK
    {
        //方法功能：把链表右旋K个位置
        public static void Rotate(LNode head, int k)
        {
            if (head == null || head.next == null)
            {
                return;
            }

            //fast指针先走k步,然后与slow指针同时向后走
            LNode slow, fast, tmp;
            slow = fast = head.next;
            int i;
            for (i = 0; i < k && fast != null; ++i)
            {
                //前移k步
                fast = fast.next;
            }
            //判断k是否超出链表长度
            if (i < k)
            {
                return;
            }
            //循环结束后slow指向链表倒数第k+1个元素，fast指向链表最后一个元素
            while (fast.next != null)
            {
                slow = slow.next;
                fast = fast.next;
            }
            tmp = slow;
            slow = slow.next;
            tmp.next = null;
            fast.next = head.next;
            head.next = slow;
        }

        public static LNode ConstructList()
        {
            int i = 1;
            LNode head = new LNode();
            head.next = null;
            LNode tmp = null;
            LNode cur = head;
            //构造第一个链表
            for (; i < 8; i++)
            {
                tmp = new LNode();
                tmp.data = i;
                tmp.next = null;
                cur.next = tmp;
                cur = tmp;
            }
            return head;
        }

        //顺序打印单链表结点的数据
        public static void PrintList(LNode head)
        {
            for (LNode cur = head.next; cur != null; cur = cur.next)
            {
                Console.Write(cur.data + " ");
            }
        }


    }
}
