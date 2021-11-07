using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Nowcoder.Medium.NC2
{
    /// <summary>
    /// NC2 重排链表
    /// </summary>
    public class Class2
    {
        public void reorderList(ListNode head)
        {
            if (head == null || head.next == null)
                return;
            Stack<ListNode> backlistNodes = new Stack<ListNode>();
            Queue<ListNode> frontListNodes = new Queue<ListNode>();
            int count = 1;
            var node = head.next;
            while (node != null)
            {
                backlistNodes.Push(node);
                frontListNodes.Enqueue(node);
                count++;
                node = node.next;
            }
            var isOdd = count % 2;
            node = head;
            for (int i = 0; i < count / 2; i++)
            {
                node.next = backlistNodes.Pop();
                node.next.next = frontListNodes.Dequeue();
                node = node.next.next;
            }
            if (isOdd == 1)
            {
                node.next = backlistNodes.Pop();
                node = node.next;
            }
            node.next = null;
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
