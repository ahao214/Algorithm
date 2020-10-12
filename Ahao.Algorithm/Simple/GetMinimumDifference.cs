using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 530. 二叉搜索树的最小绝对差
    /// </summary>
    public class GetMinimumDifference
    {      
        public int Method(TreeNodes root)
        {
            var list = new List<int>();
            MidTree(root, ref list);
            int minDiff = int.MaxValue;
            for (int index = 1; index < list.Count; index++)
            {
                minDiff = Math.Min(minDiff, list[index] - list[index - 1]);
            }
            return minDiff;            
        }

        public void MidTree(TreeNodes root, ref List<int> list)
        {
            if (root == null)
            {
                return;
            }
            MidTree(root.left, ref list);
            list.Add(root.val);
            MidTree(root.right, ref list);
        }

       

        public class TreeNodes
        {
            public int val;
            public TreeNodes left;
            public TreeNodes right;
            public TreeNodes(int x) { val = x; }
        }
    }
}
