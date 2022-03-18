using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo109
{
    /*
     109. 有序链表转换二叉搜索树
给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
     */
    public class Class109
    {
        public TreeNode SortedListToBST(ListNode head)
        {
            var count = 0;
            var node = head;
            while (node != null)
            {
                count++;
                node = node.next;
            }
            return SortedListToBST(ref head, count);
        }

        private TreeNode SortedListToBST(ref ListNode head, int count)
        {
            if (count == 0)
                return null;
            var left = SortedListToBST(ref head, count / 2);
            var root = new TreeNode(head.val) {
                left = left
            };
            head = head.next;
            root.right = SortedListToBST(ref head, count - count / 2 - 1);
            return root;
        }
    }

    public class TreeNode
    {
        public int val;
        public TreeNode left;
        public TreeNode right;
        public TreeNode(int val = 0, TreeNode left = null, TreeNode right = null)
        {
            this.val = val;
            this.left = left;
            this.right = right;
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
