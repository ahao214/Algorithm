﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo24
{

    public class Class24
    {
        public ListNode SwapPairs(ListNode head)
        {
            //处理特殊情况
            if (head == null || head.next == null)
            {
                return head;
            }

            ListNode pre = head.next;
            //first,second为当前要交换的节点，last为上一次交换后末尾的节点
            ListNode first, second, last = null;
            first = head;
            second = first.next;
            while (first != null && second != null)
            {
                if (second != null)
                {
                    //交换前后节点
                    first.next = second.next;
                    second.next = first;

                    if (last != null)
                    {
                        last.next = second;
                    }
                    last = first;
                }
                //将指针指向下一对要交换的节点
                first = first.next;
                if (first != null)
                {
                    second = first.next;
                }
            }
            return pre;
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
