using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Tree
{
    public class TestIsAfterOrder
    {

        /// <summary>
        /// 如何判断一个数组是否是二元查找树后序遍历的序列
        /// </summary>
        /// <param name="arr"></param>
        /// <param name="start"></param>
        /// <param name="end"></param>
        /// <returns></returns>
        public static bool IsAfterOrder(int[] arr, int start, int end)
        {
            if (arr == null)
            {
                return false;
            }

            //数组的最后一个结点必定是根结点
            int root = arr[end];
            int i, j;
            //找到第一个大于root的值，那么前面所有的结点都位于root的左子树上
            for (i = start; i < end; i++)
            {
                if (arr[i] > root)
                {
                    break;
                }
            }

            //如果序列是后续遍历的序列，那么从i开始的所有值都应该大于根结点root的值
            for (j = i; j < end; j++)
            {
                if (arr[j] < root)
                {
                    return false;
                }
            }
            bool left_IsAfterOrder = true;
            bool right_IsAfterOrder = true;
            //判断小于root值的序列是否是某一二元查找树的后续遍历
            if (i > start)
            {
                left_IsAfterOrder = IsAfterOrder(arr, start, i - 1);
            }
            //判断大于root值的序列是否是某一个二元查找树的后续遍历
            if (j < end)
            {
                right_IsAfterOrder = IsAfterOrder(arr, i, end);
            }
            return (left_IsAfterOrder && right_IsAfterOrder);
        }
    }
}
