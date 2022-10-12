using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0800_0899.demo817
{
    public class Class817
    {
        public int NumComponents(ListNode head, int[] nums)
        {
            ISet<int> numsSet = new HashSet<int>();
            foreach (int num in nums)
            {
                numsSet.Add(num);
            }
            bool inSet = false;
            int res = 0;
            while (head != null)
            {
                if (numsSet.Contains(head.val))
                {
                    if (!inSet)
                    {
                        inSet = true;
                        res++;
                    }
                }
                else
                {
                    inSet = false;
                }
                head = head.next;
            }
            return res;
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
