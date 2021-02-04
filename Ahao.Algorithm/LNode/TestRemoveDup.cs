using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.LNode
{
    /// <summary>
    ///如何从无序链表中移除重复项
    /// </summary>
    public class TestRemoveDup
    {
        public static void RemoveDup(LNode head)
        {
            if (head == null || head.next == null)
            {
                return;
            }
            LNode outerCur = head.next;   //外层循环指针，指向链表第一个结点
            LNode innerCur = null;          //内层循环用来遍历outerCur后面的结点
            LNode innerPre = null;          //innerCur的前驱结点
            for (; outerCur != null; outerCur = outerCur.next)
            {
                for (innerCur = outerCur.next, innerPre = outerCur; innerCur != null;)
                {
                    //找到重复的结点并删除
                    if (outerCur.data == innerCur.data)
                    {
                        innerPre.next = innerCur.next;
                        innerCur = innerCur.next;
                    }
                    else
                    {
                        innerPre = innerCur;
                        innerCur = innerCur.next;
                    }
                }
            }
        }


        #region 递归法

        public static LNode RemoveDupRecursion(LNode head)
        {
            if (head.next == null)
            {
                return head;
            }
            LNode pointer = null;
            LNode cur = head;
            //对从head.next为首的子链表删除重复的结点
            head.next = RemoveDupRecursion(head.next);
            pointer = head.next;
            //找出以head.next为首的子链表中与head结点相同的结点并删除
            while (pointer != null)
            {
                if (head.data == pointer.data)
                {
                    cur.next = pointer.next;
                    pointer = cur.next;
                }
                else
                {
                    pointer = pointer.next;
                    cur = cur.next;
                }
            }
            return head;
        }

        //方法功能：对带头结点的单链表删除重复结点，输入参数：head：指向链表头结点
        public static void RemoveDupDG(LNode head)
        {
            if (head == null)
            {
                return;
            }
            head.next = RemoveDupRecursion(head.next);
        }

        #endregion


    }
}
