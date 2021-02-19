using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Web.Management;

namespace Ahao.Algorithm.Tree
{
    /// <summary>
    /// 对二叉树进行镜像反转
    /// </summary>
    public class TestReverseTree
    {
        public static void ReverseTree(BiTNode root)
        {
            if (root == null)
            {
                return;
            }

            ReverseTree(root.Lchild);
            ReverseTree(root.Rchild);
            BiTNode tmp = root.Lchild;
            root.Lchild = root.Rchild;
            root.Rchild = tmp;
        }

        public static BiTNode arraytotree(int[] arr, int start, int end)
        {
            BiTNode root = null;
            if (end >= start)
            {
                root = new BiTNode();
                int mid = (start + end + 1) / 2;
                //树的根结点为数组中间的元素
                root.Data = arr[mid];
                //递归的用左半部分数组构造root的左子树
                root.Lchild = arraytotree(arr, start, mid - 1);
                //递归的用右半部分数组构造root的右子树
                root.Rchild = arraytotree(arr, mid + 1, end);
            }
            else
            {
                root = null;
            }
            return root;
        }


        public static void PrintTreeLayer(BiTNode root)
        {
            if (root == null)
            {
                return;
            }

            BiTNode p;
            Queue<BiTNode> queue = new Queue<BiTNode>();
            //树根结点进队列
            queue.Enqueue(root);
            while (queue.Count > 0)
            {
                p = queue.Dequeue();
                //访问当前结点
                Console.Write(p.Data + " ");
                //如果这个结点的左孩子不为空则入队列
                if (p.Lchild != null)
                {
                    queue.Enqueue(p.Lchild);
                }
                //如果这个结点的右孩子不为空则入队列
                if (p.Rchild != null)
                {
                    queue.Enqueue(p.Rchild);
                }
            }
        }

    }
}
