using System;
using System.Collections.Generic;
using System.ComponentModel.Design.Serialization;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Tree
{
    /// <summary>
    /// 求一颗二叉树的最大子树的和
    /// </summary>
    public class TestFindMaxSubTree
    {
        private static int maxSum = int.MinValue;

        /// <summary>
        /// 方法功能：求最大子树
        /// 输入参数：root-根结点；maxSum最大子树结点的和
        ///                 maxRoot指向最大子树的根结点
        ///返回值：以root为根结点子树 所有结点的和        
        /// </summary>
        /// <param name="root"></param>
        /// <param name="maxRoot"></param>
        /// <returns></returns>
        public static int FindMaxSubTree(BiTNode root, BiTNode maxRoot)
        {
            if (root == null)
            {
                return 0;
            }

            //求root左子树所有结点的和
            int lmax = FindMaxSubTree(root.Lchild, maxRoot);
            //求root右子树所有结点的和
            int rmax = FindMaxSubTree(root.Rchild, maxRoot);
            int sum = lmax + rmax + root.Data;
            //以root为根的子树的和大于前面求出的最大值
            if (sum > maxSum)
            {
                maxSum = sum;
                maxRoot.Data = root.Data;
            }
            //返回以root为根结点的子树的所有结点的和
            return sum;
        }

        /// <summary>
        /// 方法功能：构造二叉树
        /// 返回值：返回新构造的二叉树的根结点
        /// </summary>
        /// <returns></returns>
        public static BiTNode constructTree()
        {
            BiTNode root = new BiTNode();
            BiTNode node1 = new BiTNode();
            BiTNode node2 = new BiTNode();
            BiTNode node3 = new BiTNode();
            BiTNode node4 = new BiTNode();
            root.Data = 6;
            node1.Data = 3;
            node2.Data = -7;
            node3.Data = -1;
            node4.Data = 9;
            root.Lchild = node1;
            root.Rchild = node2;
            node1.Lchild = node3;
            node1.Rchild = node4;
            node2.Lchild = node2.Rchild = node3.Lchild = node3.Rchild = node4.Lchild = node4.Rchild = null;
            return root;
        }


    }
}
