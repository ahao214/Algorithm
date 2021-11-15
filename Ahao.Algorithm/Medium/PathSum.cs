using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Secondary
{
    /// <summary>
    /// 113.路径总和(2)
    /// </summary>
    public class PathSum
    {
        public IList<IList<int>> Method(TreeNode root, int sum)
        {
            var result = new List<IList<int>>();
            if (root == null)
            {
                return result;
            }
            GetResult(root, sum, new List<int>(), result);
            return result;
        }

        private void GetResult(TreeNode root, int sum, List<int> path, List<IList<int>> result)
        {
            if (root == null)
            {
                return;
            }
            if (root.left == null && root.right == null)
            {
                sum -= root.val;
                path.Add(root.val);
                if (sum == 0)
                {
                    result.Add(new List<int>(path));
                }
                path.RemoveAt(path.Count - 1);
                return;
            }
            path.Add(root.val);
            GetResult(root.left, sum - root.val, path, result);
            GetResult(root.right, sum - root.val, path, result);
            path.RemoveAt(path.Count - 1);
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
