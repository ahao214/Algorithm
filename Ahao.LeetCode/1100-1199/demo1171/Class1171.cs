using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1100_1199.demo1171
{
    public class Class1171
    {

        public ListNode RemoveZeroSumSublists(ListNode head)
        {
            int prefix = 0;
            ListNode dummy = new ListNode(0);
            dummy.next = head;
            Dictionary<int, ListNode> seen = new Dictionary<int, ListNode>();
            seen[0] = dummy;
            for (ListNode node = dummy; node != null; node = node.next)
            {
                prefix += node.val;
                seen[prefix] = node;
            }
            prefix = 0;
            for (ListNode node = dummy; node != null; node = node.next)
            {
                prefix += node.val;
                node.next = seen[prefix].next;
            }
            return dummy.next;
        }


        public ListNode RemoveZeroSumSublists2(ListNode head)
        {
            // <sum, lastNode>
            Dictionary<int, ListNode> sumMap = new Dictionary<int, ListNode>();
            ListNode dummy = new ListNode(-1, head);
            ListNode p = head;
            int sum = 0;
            sumMap.Add(0, dummy);
            while (p != null)
            {
                sum += p.val;
                if (sumMap.ContainsKey(sum))
                {
                    ListNode node = sumMap.GetValueOrDefault(sum);
                    ListNode del = node.next;
                    node.next = p.next;

                    int dSum = sum;
                    while (del != p)
                    {
                        dSum += del.val;
                        sumMap.Remove(dSum);
                        del = del.next;
                    }

                }
                else
                {
                    sumMap.Add(sum, p);
                }
                p = p.next;
            }
            return dummy.next;

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
