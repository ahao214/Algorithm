using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1000_1099.demo1019
{
    public class Class1019
    {        

        public int[] NextLargerNodes(ListNode head)
        {
            IList<int> res = new List<int>();
            Stack<int[]> stack = new Stack<int[]>();

            ListNode cur = head;
            int idx = -1;
            while (cur != null)
            {
                ++idx;
                res.Add(0);
                while (stack.Count > 0 && stack.Peek()[0] < cur.val)
                {
                    res[stack.Pop()[1]] = cur.val;
                }
                stack.Push(new int[] { cur.val, idx });
                cur = cur.next;
            }

            return res.ToArray();
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
