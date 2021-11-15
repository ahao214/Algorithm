using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm
{
    public class FindMode
    {
        /// <summary>
        /// 501.二叉搜索树中的众数
        /// </summary>
        /// <param name="root"></param>
        /// <returns></returns>
         //记录众数出现的最大次数
        int maxCount = 0;
        //记录当前元素出现的次数
        int curCount = 0;
        //前驱节点
        TreeNode preNode = null;
        public int[] Method(TreeNode root)
        {
            List<int> result = new List<int>();
            GetResult(root, result);
            return result.ToArray();
        }

        private void GetResult(TreeNode root, List<int> result)
        {
            if (root == null)
            {
                return;
            }

            GetResult(root.left, result);
            if (preNode != null)
            {
                if (root.val == preNode.val)
                {
                    curCount += 1;
                }
                else
                {
                    curCount = 1;
                }
                //curCount = root.val == preNode.val ? curCount + 1 : 1;
            }
            else
            {
                curCount = 1;
            }
            if (curCount == maxCount)
            {
                result.Add(root.val);
            }
            else if (curCount > maxCount)
            {
                result.Clear();
                result.Add(root.val);
                maxCount = curCount;
            }
            preNode = root;

            GetResult(root.right, result);
        }

        public class TreeNode
        {
            public int val;
            public TreeNode left;
            public TreeNode right;
            public TreeNode(int x) { val = x; }
        }
    }
}
