using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Tree
{
    /// <summary>
    /// 找出排序二叉树上任意两个结点的最近共同父结点
    /// </summary>
    public class TestGetPathFromRoot
    {
        /// <summary>
        /// 方法功能：获取二叉树从根结点root到node结点的路径
        /// 输入参数：root-根结点 node-二叉树中的某个结点；s-用来存储路径的栈
        /// </summary>
        /// <param name="root"></param>
        /// <param name="node"></param>
        /// <param name=""></param>
        /// <returns></returns>
        public static bool getPathFromRoot(BiTNode root, BiTNode node, Stack<BiTNode> s)
        {
            if (root == null)
            {
                return false;
            }

            if (root == node)
            {
                s.Push(root);
                return true;
            }

            //如果node结点在root结点的左子树或右子树上
            //那么root就是node的祖先结点，把它加到栈里
            if (getPathFromRoot(root.Lchild, node, s) || getPathFromRoot(root.Rchild, node, s))
            {
                s.Push(root);
                return true;
            }
            return false;

        }

        /// <summary>
        /// 方法功能；查找二叉树中两个结点最近的共同父结点
        /// 输入参数：root-根结点；node1和node2为二叉树中两个结点
        /// 返回值：node1和node2最近的共同父结点
        /// </summary>
        /// <param name="root"></param>
        /// <param name="root1"></param>
        /// <param name="root2"></param>
        /// <returns></returns>
        public static BiTNode FindParentNode(BiTNode root, BiTNode node1, BiTNode node2)
        {
            Stack<BiTNode> stack1 = new Stack<BiTNode>();   //保存从root到node1的路径
            Stack<BiTNode> stack2 = new Stack<BiTNode>();   //保存从root到node2的路径
            //获取从root到node1的路径
            getPathFromRoot(root, node1, stack1);
            //获取从root到node2的路径
            getPathFromRoot(root, node2, stack2);
            BiTNode commomParent = null;
            //获取最靠近node1和node2的父结点
            while (stack1.Peek() == stack2.Peek())
            {
                commomParent = stack1.Peek();
                stack1.Pop();
                stack2.Pop();
            }
            return commomParent;
        }
    }
}
