using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo92
{
    /*
     92. 反转链表 II
给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。
     */
    public class Class92
    {
        public ListNode ReverseBetween(ListNode head, int left, int right)
        {
            ListNode XX = head;
            while (head != null)
            {
                left--;
                right--;
                if (left == right)
                {
                    break;
                }

                ListNode iterNode = head.next;
                if (left == 1)
                {
                    var (x, y) = convers(iterNode, right - left);
                    head.next = x;
                    break;
                }
                if (left == 0)
                {
                    var (x, y) = convers(head, right - left);
                    return x;
                }
                head = iterNode;
            }
            return XX;
        }

        //ListNode? tail=new ListNode();
        private (ListNode?, ListNode?) convers(ListNode head, int j)
        {
            ListNode? taill = new ListNode();

            if (head.next == null || j == 0) { return (head, head.next); }
            ListNode iternode = head.next;
            j--;
            var (x, y) = convers(iternode, j);
            iternode.next = head;
            head.next = y;

            return (x, y);
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
