﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo21
{
    /*
     21. 合并两个有序链表
     将两个升序链表合并为一个新的升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
     */
    public class Class21
    {
        public ListNode MergeTwoLists(ListNode list1, ListNode list2)
        {
            var dummy = new ListNode();
            var tail = dummy;
            var node1 = list1;
            var node2 = list2;
            while (list1 != null && list2 != null)
            {
                var n1 = list1.val;
                var n2 = list2.val;
                if (n1 <= n2)
                {
                    tail = tail.next = list1;
                    list1 = list1.next;
                }
                else
                {
                    tail = tail.next = list2;
                    list2 = list2.next;
                }
            }
            var nodes = list1 ?? list2;
            while (nodes != null)
            {
                tail = tail.next = nodes;
                nodes = nodes.next;
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
