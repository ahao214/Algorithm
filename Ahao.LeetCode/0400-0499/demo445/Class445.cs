using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0400_0499.demo445
{
    public class Class445
    {

        public ListNode AddTwoNumbers(ListNode l1, ListNode l2)
        {
            Stack<int> stack1 = new Stack<int>();
            Stack<int> stack2 = new Stack<int>();
            while (l1 != null)
            {
                stack1.Push(l1.val);
                l1 = l1.next;
            }
            while (l2 != null)
            {
                stack2.Push(l2.val);
                l2 = l2.next;
            }
            int carry = 0;
            ListNode ans = null;
            while (stack1.Count > 0 || stack2.Count > 0 || carry != 0)
            {
                int a = stack1.Count == 0 ? 0 : stack1.Pop();
                int b = stack2.Count == 0 ? 0 : stack2.Pop();
                int cur = a + b + carry;
                carry = cur / 10;
                cur %= 10;
                ListNode curnode = new ListNode(cur);
                curnode.next = ans;
                ans = curnode;
            }
            return ans;
        }

    }


    public class ListNode
    {
        public int val;
        public ListNode next;
        public ListNode(int val = 0, ListNode next = null)
        {
            this.val = val;
            this.next = next;
        }
    }
}
