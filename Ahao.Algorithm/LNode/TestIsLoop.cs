using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Remoting.Metadata.W3cXsd2001;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.LNode
{
    /// <summary>
    /// 检查一个较大的单链表是否有环
    /// </summary>
    public class TestIsLoop
    {
        //构造单链表
        public static LNode ConstructList()
        {
            int i = 1;
            LNode head = new LNode();
            head.next = null;
            LNode tmp = null;
            LNode cur = head;
            //构造一个链表
            for(;i<8;i++)
            {
                tmp = new LNode();
                tmp.data = i;
                tmp.next = null;
                cur.next = tmp;
                cur = tmp;
            }
            cur.next = head.next.next.next;
            return head;
        }


        /// <summary>
        /// 方法功能：判断单链表是否有环
        /// 输入参数：head-链表头结点
        /// 返回值：null-无环，否则返回slow与fast相遇点的结点
        /// </summary>
        /// <param name="head"></param>
        /// <returns></returns>
        public static LNode IsLoop(LNode head)
        {

            if(head ==null || head .next ==null )
            {
                return null;
            }
            //初始化slow与fast都指向链表第一个结点
            LNode slow = head.next;
            LNode fast = head.next;
            while (fast!=null && fast.next !=null )
            {
                slow = slow.next;
                fast = fast.next.next;
                if (slow ==fast )
                {
                    return slow;
                }
            }
            return null; 


        }

        /// <summary>
        /// 方法功能：找出环的入口点
        /// 输入参数：head-fast和slow相遇点
        /// 返回值：null-无环，否则返回slow与fast指针相遇点的结点
        /// </summary>
        /// <param name="head"></param>
        /// <param name="meetNode"></param>
        /// <returns></returns>

        public static LNode FindLoopNode(LNode head, LNode meetNode)
        {
            LNode first = head.next;
            LNode second = meetNode;
            while(first!=second)
            {
                first = first.next;
                second = second.next;
            }
            return first;
        }

    }
}
