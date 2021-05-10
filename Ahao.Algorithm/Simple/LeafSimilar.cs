using System;
using System.Collections.Generic;
using System.ComponentModel.Design;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 872. 叶子相似的树
    /// </summary>
    public class LeafSimilar
    {
        public bool Method(TreeNodeLeafSimilar root1, TreeNodeLeafSimilar root2)
        {
            List<int> leaf1 = new List<int>();
            List<int> leaf2 = new List<int>();
            DFS(root1, leaf1);
            DFS(root2, leaf2);
            if (leaf1.Count != leaf2.Count)
                return false;
            for (int i = 0; i < leaf1.Count; i++)
            {
                if (leaf1[i] != leaf2[i])
                {
                    return false;
                }
            }
            return true;
        }


        public void DFS(TreeNodeLeafSimilar root, List<int> lst)
        {
            if (root == null)
                return;
            if (root.left == null && root.right == null)
                lst.Add(root.val);
            if (root.left != null)
                DFS(root.left, lst);
            if (root.right != null)
                DFS(root.right, lst);
        }
    }



    public class TreeNodeLeafSimilar
    {
        public int val;
        public TreeNodeLeafSimilar left;
        public TreeNodeLeafSimilar right;
        public TreeNodeLeafSimilar(int val = 0, TreeNodeLeafSimilar left = null, TreeNodeLeafSimilar right = null)
        {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }
}
