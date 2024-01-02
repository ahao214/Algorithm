using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2400_2499.demo2487
{
    public class Class2487
    {
        public ListNode RemoveNodes(ListNode head)
        {
            if (head == null)
            {
                return null;
            }
            head.next = RemoveNodes(head.next);
            if (head.next != null && head.val < head.next.val)
            {
                return head.next;
            }
            else
            {
                return head;
            }
        }

        public ListNode RemoveNodes2(ListNode head)
        {
            Stack<ListNode> stack = new Stack<ListNode>();
            for (; head != null; head = head.next)
            {
                stack.Push(head);
            }
            for (; stack.Count > 0; stack.Pop())
            {
                if (head == null || stack.Peek().val >= head.val)
                {
                    stack.Peek().next = head;
                    head = stack.Peek();
                }
            }
            return head;
        }


        public ListNode RemoveNodes3(ListNode head)
        {
            head = Reverse(head);
            for (ListNode p = head; p.next != null;)
            {
                if (p.val > p.next.val)
                {
                    p.next = p.next.next;
                }
                else
                {
                    p = p.next;
                }
            }
            return Reverse(head);
        }

        public ListNode Reverse(ListNode head)
        {
            ListNode dummy = new ListNode();
            while (head != null)
            {
                ListNode p = head;
                head = head.next;
                p.next = dummy.next;
                dummy.next = p;
            }
            return dummy.next;
        }


    }

    public class ListNode
    {
        public int val;
        public ListNode next;
        public ListNode(int val =0,ListNode next=null)
        {
            this.val = val;
            this.next = null;
        }
    }
}
