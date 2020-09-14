using System;
using System.Collections.Generic;


namespace Ahao.Algorithm
{
    /// <summary>
    /// 637. 二叉树的层平均值
    /// </summary>
    public class AverageOfLevels
    {
        //public IList<double> Method(TreeNode root)
        //{
        //    List<Double> result = new List<Double>();
        //    Queue<TreeNode> queue = new Queue<TreeNode>();
        //    queue.Enqueue(root);
        //    while (queue.Count > 0)
        //    {
        //        double sum = 0;
        //        int size = queue.Count;
        //        for (int i = 0; i < size; i++)
        //        {
        //            TreeNode node = queue.Dequeue();
        //            sum += node.val;
        //            TreeNode left = node.left;
        //            TreeNode  right = node.right;
        //            if (left != null)
        //            {
        //                queue.Enqueue(left);
        //            }
        //            if (right != null)
        //            {
        //                queue.Enqueue(right);
        //            }
        //        }
        //        result.Add(sum / size);
        //    }
        //    return result;
        //}
    }
}
