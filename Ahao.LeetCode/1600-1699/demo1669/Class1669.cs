using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1600_1699.demo1669
{
    public class Class1669
    {
        public ListNode MergeInBetween(ListNode list1, int a, int b, ListNode list2)
        {
            ListNode preA = list1;
            for (int i = 0; i < a - 1; i++)
            {
                preA = preA.next;
            }
            ListNode preB = preA;
            for (int i = 0; i < b - a + 2; i++)
            {
                preB = preB.next;
            }
            preA.next = list2;
            while (list2.next != null)
            {
                list2 = list2.next;
            }
            list2.next = preB;
            return list1;
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
