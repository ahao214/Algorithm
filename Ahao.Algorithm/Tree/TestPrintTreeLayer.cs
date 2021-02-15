using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Web.UI;

namespace Ahao.Algorithm.Tree
{
   
    public class  TestPrintTreeLayer
    {
        /// <summary>
        /// 方法功能：用层序遍历的方式打印出二叉树结点的内容
        /// 输入参数：root-二叉树根结点
        /// </summary>
        public static void PrintTreeLayer(BiTNode root)
        {
            if (root == null)
            {
                return;
            }

            BiTNode p;
            Queue<BiTNode> queue = new Queue<BiTNode>();
            //二叉树根节点进队列
            queue.Enqueue(root);
            while (queue.Count() > 0)
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
