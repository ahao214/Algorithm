using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.LNode
{
    /// <summary>
    /// 对链表进行重新排序
    /// </summary>
    public class TestFindMiddleNode
    {
        /// <summary>
        /// 方法功能：找出链表head的中间点，把链表从中间断成两个链表
        /// 输入参数：head-链表头结点
        /// 返回值：指向链表的中间结点的指针
        /// </summary>
        /// <param name="head"></param>
        /// <returns></returns>
        private static LNode FindMiddleNode(LNode head)
        {
            if(head ==null || head.next ==null )
            {
                return head;
            }
            LNode fast = head;  //块指针每次走两步
            LNode slow = head;//慢指针每次走一步
            LNode slowPre = head;
            //当fast到链表尾时，slow恰好指向链表的中间结点
            while(fast!=null && fast.next !=null )
            {
                slowPre = slow;
                slow = slow.next;
                fast = fast.next.next;
            }
            //把链表断成两个独立的子链表
            slowPre.next = null;
            return slow;
        }


        /// <summary>
        /// 方法功能：对不带头结点的单链表翻转
        /// 输入参数：head-指向链表头结点
        /// </summary>
        /// <param name="head"></param>
        /// <returns></returns>
        private static LNode Reverse(LNode head)
        {
            if(head ==null || head .next ==null )
            {
                return head;
            }
            LNode pre = head;//前驱结点
            //当前结点
            LNode cur = head.next;
            //后续结点
            LNode next = cur.next;
            pre.next = null;
            //使当前遍历到的结点cur指向其前驱结点
            while(cur !=null )
            {
                next = cur.next;
                cur.next = pre;
                pre = cur;
                cur = cur.next;
                cur = next;
            }
            return pre;
        }

        /// <summary>
        /// 方法功能：对链表进行排序
        /// 输入参数：head-指向链表头结点
        /// </summary>
        /// <param name="head"></param>
        public static void Reorder(LNode head)
        {
            if(head ==null || head .next ==null )
            {
                return;
            }
            //前半部分链表第一个结点
            LNode cur1 = head.next;
            LNode mid = FindMiddleNode(head.next);
            //后半部分链表逆序后的第一个结点
            LNode cur2 = Reverse(mid);
            LNode tmp = null;
            //合并两个链表
            while (cur1 .next !=null )
            {
                tmp = cur1.next;
                cur1.next = cur2;
                cur1 = tmp;
                tmp = cur2.next;
                cur2.next = cur1;
                cur2 = tmp; 
            }
            cur1.next = cur2;
        }

    }
}
