using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Runtime.InteropServices.WindowsRuntime;
using System.Runtime.Remoting.Messaging;
using System.Text;
using System.Threading.Tasks;
using System.Web.Management;

namespace Ahao.Algorithm.LNode
{
    /// <summary>
    /// 找出单链表中的倒数第K个元素
    /// </summary>
    public class TestConstructListK
    {
        //构造一个单链表
        public static LNode ConstructList()
        {
            int i = 1;
            LNode head = new LNode();
            head.next = null;
            LNode tmp = null;
            LNode cur = head;
            //构造第一个链表
            for(;i<8;i++)
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
            for (LNode cur = head.next; cur != null; cur = cur.next )
            {
                Console.Write(cur.data + " ");
            }
        }

        /// <summary>
        /// 方法功能：找到链表倒数第K个结点
        /// 输入参数：head-链表头结点
        /// 返回值：指向倒数第K个结点的指针
        /// </summary>
        /// <param name="head"></param>
        /// <param name="k"></param>
        /// <returns></returns>
        public static LNode FindLastK(LNode head,int k)
        {
            if(head ==null || head .next ==null )
            {
                return head;
            }
            LNode slow, fast;
            slow = fast = head.next;
            int i;
            for(i=0;i<k && fast !=null; ++i)
            {
                //前移k步
                fast = fast.next;
            }
            //判断k是否已超出链表长度
            if(i<k)
            {
                return null;
            }
            while (fast !=null )
            {
                slow = slow.next;
                fast = fast.next;
            }
            return slow;
        }

    }
}
