using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 437. 路径总和 III
    /// </summary>
    public class PathSumII
    {
        public int Method(TreeNode root, int targetSum)
        {
            int result = 0;
            if (root == null)
            {
                return result;
            }

            result = GetSum(root, targetSum);
            result += Method(root.left, targetSum);
            result += Method(root.right, targetSum);
            return result;
        }

        public int GetSum(TreeNode root, int target)
        {
            int result = 0;
            if (root == null)
            {
                return result;
            }

            int value = root.val;
            if (value == target)
            {
                result++;
            }

            result += GetSum(root.left, target - value);
            result += GetSum(root.right, target - value);
            return result;
        }
    }
}
