using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Tree
{
    /// <summary>
    /// 在二叉树中找出路径最大的和
    /// </summary>
    public class TestFindMaxPath
    {
        //求a、b、c的最大值
        int Max(int a, int b, int c)
        {
            int max = a > b ? a : b;
            max = max > c ? max : c;
            return max;
        }

        /// <summary>
        /// 寻找最长路径
        /// </summary>
        /// <param name="root"></param>
        /// <param name="max"></param>
        /// <returns></returns>
        public int FindMaxPathrecursive(TreeNode root, IntRef max)
        {
            if (root == null)
            {
                return 0;
            }
            else
            {
                //求左子树以root->left为起始结点的最大路径和
                int sumLeft = FindMaxPathrecursive(root.Left, max);
                //求右子树以root->right为起始结点的最大路径和
                int sumRight = FindMaxPathrecursive(root.Right, max);

                //求以root为起始结点，叶子结点为结束结点的最大路径和
                int allMax = root.Val + sumLeft + sumRight;
                int leftMax = root.Val + sumLeft;
                int rightMax = root.Val + sumRight;
                int tmpMax = Max(allMax, leftMax, rightMax);
                if (tmpMax > max.Val)
                {
                    max.Val = tmpMax;
                }
                int subMax = sumLeft > sumRight ? sumLeft : sumRight;
                //返回以root为起始结点，叶子结点为结束结点的最大路径和
                return root.Val + subMax;
            }
        }


        public int FindMaxPath(TreeNode root)
        {
            IntRef max = new IntRef();
            max.Val = int.MinValue;
            FindMaxPathrecursive(root, max);
            return max.Val;
        }

    }
}
