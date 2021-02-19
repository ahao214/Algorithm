using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Tree
{
    /// <summary>
    /// 在二叉树中找出与输入整数相等的所有路径
    /// </summary>
    public class TestFindRoad
    {
        /// <summary>
        /// 方法功能：打印出满足所有结点的和等于num的所有路径
        /// 参数：root-0二叉树根结点；num：给定的整数；sum：当前路径上所有结点的和
        /// v:用来存储从根结点到当前遍历到结点的路径
        /// </summary>
        /// <param name="root"></param>
        /// <param name="num"></param>
        /// <param name="sum"></param>
        /// <param name="v"></param>
        public static void FindRoad(BiTNode root, int num, int sum, List<int> v)
        {
            //记录当前遍历的root结点
            sum += root.Data;
            v.Add(root.Data);
            //当前结点是叶子结点且遍历的路径上所有结点的和等于sum
            if (root.Lchild == null && root.Rchild == null && sum == num)
            {
                for (int i = 0; i < v.Count; i++)
                {
                    Console.Write(v[i] + " ");
                }
                Console.WriteLine();
            }
            //遍历root的左子树
            if (root.Lchild != null)
            {
                FindRoad(root.Lchild, num, sum, v);
            }
            //遍历root的右子树
            if (root.Rchild != null)
            {
                FindRoad(root.Rchild, num, sum, v);
            }
            //清除遍历的路径
            sum -= v[v.Count - 1];
            v.Remove(v.Count - 1);
        }


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
