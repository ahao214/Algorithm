using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium
{
    /*
     6013. 合并零之间的节点
     给你一个链表的头节点 head ，该链表包含由 0 分隔开的一连串整数。链表的 开端 和 末尾 的节点都满足 Node.val == 0 。

对于每两个相邻的 0 ，请你将它们之间的所有节点合并成一个节点，其值是所有已合并节点的值之和。然后将所有 0 移除，修改后的链表不应该含有任何 0 。

 返回修改后链表的头节点 head 。
     */
    public class Class6013
    {
        public ListNode MergeNodes(ListNode head)
        {
            ListNode now = head;
            while (now != null)
            {
                if (now.val == 0)
                {
                    now = now.next;
                    continue;
                }
                ListNode nxt = now.next;
                if (nxt.val != 0)
                {
                    now.val += nxt.val;
                    now.next = nxt.next;
                }
                else
                {
                    now = now.next;
                }
            }
            now = head.next;
            while (now != null)
            {
                ListNode nxt = now.next;
                if (nxt.val == 0)
                {
                    now.next = nxt.next;
                }
                now = now.next;
            }
            return head.next;
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
