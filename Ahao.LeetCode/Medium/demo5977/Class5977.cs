using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo5977
{
    /// <summary>
    /// 5977. 最少交换次数来组合所有的 1 II
    /// 交换 定义为选中一个数组中的两个 互不相同 的位置并交换二者的值。
    ///环形 数组是一个数组，可以认为 第一个 元素和 最后一个 元素 相邻 。
    ////给你一个 二进制环形 数组 nums ，返回在 任意位置 将数组中的所有 1 聚集在一起需要的最少交换次数。
    /// </summary>
    public class Class5977
    {
        public int MinSwaps(int[] nums)
        {
            int n = nums.Length;
            if (n == 1)
            {
                return nums[0] == 1 ? 0 : 1;
            }
            int countOne = 0;
            int countZero = 0;
            for (int i = 0; i < nums.Length; i++)
            {
                if (nums[i] == 1)
                    countOne++;
                else
                    countZero++;
            }
            return Math.Abs(countOne - countZero);
        }
    }
}
