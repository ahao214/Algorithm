using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo2
{
    public class Class2
    {
        public ListNode AddTwoNumbers(ListNode l1, ListNode l2)
        {
            var node1 = l1;
            var node2 = l2;
            var c = 0;
            var dummy = new ListNode(0);
            var tail = dummy;
            while (node1 != null | node2 != null)
            {
                var nOne = node1?.val ?? 0;
                var nTwo = node2?.val ?? 0;
                var n = nOne + nTwo + c;
                tail = tail.next = new ListNode(n % 10);
                c = n / 10;
                node1 = node1?.next;
                node2 = node2?.next;
            }
            if (c != 0)
            {
                tail = tail.next = new ListNode(c);
            }
            return dummy.next;

        }

        public ListNode AddTwoNumbers2(ListNode l1, ListNode l2)
        {
            if (l1 == null)
                return l2;
            if (l2 == null)
                return l1;

            //虚拟头节点
            ListNode dummyHead = new ListNode(0);
            //进位值
            int carry = 0;
            ListNode last = dummyHead;
            while (l1 != null || l2 != null)
            {
                int v1 = 0;
                if (l1 != null)
                {
                    v1 = l1.val;
                    l1 = l1.next;
                }
                int v2 = 0;
                if (l2 != null)
                {
                    v2 = l2.val;
                    l2 = l2.next;
                }
                int sum = v1 + v2 + carry;
                carry = sum / 10;
                //sum的个位数做为新节点的值
                last.next = new ListNode(sum % 10);
                last = last.next;
            }
            if (carry > 0)
            {
                last.next = new ListNode(carry);
            }
            return dummyHead.next;
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
