using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo1609
{
    public class Class1609
    {
        public bool IsEvenOddTree(TreeNode root)
        {
            Queue<TreeNode> queue = new Queue<TreeNode>();
            queue.Enqueue(root);
            int level = 0;
            while (queue.Count > 0)
            {
                int size = queue.Count;
                int prevValue = 0;
                if (level % 2 == 0)
                {
                    prevValue = int.MinValue;
                }
                else
                {
                    prevValue = int.MaxValue;
                }

                for (int i = 0; i < size; i++)
                {
                    TreeNode node = queue.Dequeue();
                    var value = node.val;
                    //偶数行是奇数，奇数行是偶数，行数加数值肯定是奇数
                    if ((level + value) % 2 == 0)
                    {
                        return false;
                    }
                    if ((level % 2 == 0 && value <= prevValue) || (level % 2 == 1 && value >= prevValue))
                    {
                        return false;
                    }
                    prevValue = value;
                    if (node.left != null)
                    {
                        queue.Enqueue(node.left);
                    }
                    if (node.right != null)
                    {
                        queue.Enqueue(node.right);
                    }
                }
                level++;
            }
            return true;
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
