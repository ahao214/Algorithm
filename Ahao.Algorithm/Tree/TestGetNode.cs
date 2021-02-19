using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.AccessControl;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Tree
{
    /// <summary>
    /// 在二叉排序树中找出第一个大于中间值的结点
    /// </summary>
    public class TestGetNode
    {
        /// <summary>
        ///方法功能：查找值最小的结点
        ///输入参数：root-根结点
        /// </summary>
        /// <param name="root"></param>
        /// <returns></returns>
        public static BiTNode GetMinNode(BiTNode root)
        {
            if (root == null)
            {
                return root;
            }
            while (root.Lchild != null)
            {
                root = root.Lchild;
            }
            return root;
        }

        /// <summary>
        /// 方法功能：查找值最大的结点
        /// 输入参数：root-根结点
        /// </summary>
        /// <param name="root"></param>
        /// <returns></returns>
        public static BiTNode GetMaxNode(BiTNode root)
        {
            if (root == null)
            {
                return root;
            }
            while (root.Rchild != null)
            {
                root = root.Rchild;
            }
            return root;
        }


        public static BiTNode GetNode(BiTNode root)
        {
            BiTNode maxNode = GetMaxNode(root);
            BiTNode minNode = GetMinNode(root);

            int mid = (maxNode.Data + minNode.Data) / 2;
            BiTNode result = null;
            while (root != null)
            {
                //当前结点的值不大于f，则在右子树上找
                if (root.Data <= mid)
                {
                    root = root.Rchild;
                }
                //否在左子树上找
                else
                {
                    result = root;
                    root = root.Lchild;
                }
            }
            return result;
        }


        public static BiTNode arraytoTree(int[] arr, int start, int end)
        {
            BiTNode root = null;
            if (end >= start)
            {
                root = new BiTNode();
                int mid = (start + end + 1) / 2;
                //树的根结点为数组中间的元素
                root.Data = arr[mid];
                //递归的用左半部分数组构造root的左子树
                root.Lchild = arraytoTree(arr, start, mid - 1);

                //递归的用右半部分数组构造root的右子树
                root.Rchild = arraytoTree(arr, mid + 1, end);
            }
            else
            {
                root = null;
            }
            return root;
        }

    }
}
