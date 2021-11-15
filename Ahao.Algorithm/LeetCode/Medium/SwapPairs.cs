using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 24.两两交换链表中的节点
    /// </summary>
    public class SwapPairs
    {
        public ListNodes Method(ListNodes head)
        {
            //处理特殊情况
            if (head == null || head.next == null)
            {
                return head;
            }
            
            ListNodes pre = head.next;
            //first,second为当前要交换的节点，last为上一次交换后末尾的节点
            ListNodes first, second, last = null;
            first = head;
            second = first.next;
            while (first != null && first.next != null)
            {
                if (second != null)
                {
                    //交换前后节点
                    first.next = second.next;
                    second.next = first;
                    //将当前末尾的节点指向刚交换的节点，并重设last
                    if (last != null)
                    {
                        last.next = second;
                    }
                    last = first;
                }
                //将指针指向下一对要交换的节点
                first = first.next;
                if (first != null)
                {
                    second = first.next;
                }
            }
            return pre;
        }
    }

    public class ListNodes
    {
        public int val;
        public ListNodes next;
        public ListNodes(int val = 0, ListNodes next = null)
        {
            this.val = val;
            this.next = next;
        }
    }


}
