using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Nowcoder.Easy.JZ6
{
    /// <summary>
    /// JZ6 从尾到头打印链表
    /// </summary>
    public class Class6
    {
        // 返回从尾到头的列表值序列
        public List<int> printListFromTailToHead(ListNode listNode)
        {
            List<int> lst = new List<int>();
            Stack<int> stack = new Stack<int>();
            //入栈
            while (listNode != null)
            {
                stack.Push(listNode.val);
                listNode = listNode.next;
            }
            //出栈
            while (stack.Count > 0)
            {
                lst.Add(stack.Pop());
            }
            return lst;
        }
    }

    public class ListNode
    {
        public int val;
        public ListNode next;
        public ListNode(int x)
        {
            val = x;
        }
    }
}
