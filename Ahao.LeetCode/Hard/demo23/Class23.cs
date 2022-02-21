using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Hard.demo23
{
    /*
     23. 合并K个升序链表
给你一个链表数组，每个链表都已经按升序排列。

请你将所有链表合并到一个升序链表中，返回合并后的链表。
     */
    public class Class23
    {
        public ListNode MergeKLists(ListNode[] lists)
        {
            List<int> help = new List<int>();
            for (int j = 0; j < lists.Length; j++)
            {
                ListNode ans = lists[j];
                while (ans != null)
                {
                    help.Add(ans.val);
                    ans = ans.next;
                }
            }
            help.Sort();
            ListNode res = new ListNode(0);
            int i = 0;
            ListNode helpNode = res;
            while (i < help.Count())
            {
                ListNode node = new ListNode(help[i++]);
                helpNode.next = node;
                helpNode = helpNode.next;
            }
            return res.next;
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
