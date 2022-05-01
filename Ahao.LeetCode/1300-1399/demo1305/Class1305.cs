﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1300_1399.demo1305
{
    public class Class1305
    {
        public IList<int> GetAllElements(TreeNode root1, TreeNode root2)
        {
            IList<int> nums1 = new List<int>();
            IList<int> nums2 = new List<int>();
            Inorder(root1, nums1);
            Inorder(root2, nums2);

            IList<int> merged = new List<int>();
            int p1 = 0, p2 = 0;
            while (true)
            {
                if (p1 == nums1.Count)
                {
                    while (p2 < nums2.Count)
                    {
                        merged.Add(nums2[p2++]);
                    }
                    break;
                }
                if (p2 == nums2.Count)
                {
                    while (p1 < nums1.Count)
                    {
                        merged.Add(nums1[p1++]);
                    }
                    break;
                }
                if (nums1[p1] < nums2[p2])
                {
                    merged.Add(nums1[p1++]);
                }
                else
                {
                    merged.Add(nums2[p2++]);
                }
            }
            return merged;
        }

        public void Inorder(TreeNode node, IList<int> res)
        {
            if (node != null)
            {
                Inorder(node.left, res);
                res.Add(node.val);
                Inorder(node.right, res);
            }
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
}
