﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.LC559
{
    /// <summary>
    /// 559. N 叉树的最大深度
    /// </summary>
    public class Class559
    {
        /// <summary>
        /// /深度优先搜索
        /// </summary>
        /// <param name="root"></param>
        /// <returns></returns>
        public int MaxDepth(Node root)
        {
            if (root == null)
            {
                return 0;
            }
            int maxChildDepth = 0;
            IList<Node> children = root.children;
            foreach (Node child in children)
            {
                int childDepth = MaxDepth(child);
                maxChildDepth = Math.Max(maxChildDepth, childDepth);
            }
            return maxChildDepth + 1;
        }
    }

    public class Node
    {
        public int Val;
        public IList<Node> children;
        public Node() { }
        public Node(int _val)
        {
            Val = _val;
        }
        public Node(int _val, IList<Node> _children)
        {
            Val = _val;
            children = _children;
        }
    }
}
