﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0900_0999.demo979
{
    internal class Class979
    {

        int move = 0;

        public int DistributeCoins(TreeNode root)
        {
            DFS(root);
            return move;
        }

        public int DFS(TreeNode root)
        {
            int moveleft = 0;
            int moveright = 0;
            if (root == null)
            {
                return 0;
            }
            if (root.left != null)
            {
                moveleft = DFS(root.left);
            }
            if (root.right != null)
            {
                moveright = DFS(root.right);
            }
            move += Math.Abs(moveleft) + Math.Abs(moveright);
            return moveleft + moveright + root.val - 1;
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
