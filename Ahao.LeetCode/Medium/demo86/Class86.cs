using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo86
{
    /*
     86. 分隔链表
给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。

你应当 保留 两个分区中每个节点的初始相对位置。
     */
    public class Class86
    {
        public ListNode Partition(ListNode head, int x)
        {
            var dummy1 = new ListNode(0);
            var tail1 = dummy1;
            var dummy2 = new ListNode(0);
            var tail2 = dummy2;

            var node = head;
            while (node != null)
            {
                if (node.val < x)
                    tail1 = tail1.next = node;
                else
                    tail2 = tail2.next = node;
                node = node.next;
            }
            tail1.next = dummy2.next;
            tail2.next = null;
            return dummy1.next;
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
