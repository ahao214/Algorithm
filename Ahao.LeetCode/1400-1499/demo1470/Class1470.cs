using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Simple.demo1470
{
    /*
     1470. 重新排列数组
给你一个数组 nums ，数组中有 2n 个元素，按 [x1,x2,...,xn,y1,y2,...,yn] 的格式排列。

请你将数组按 [x1,y1,x2,y2,...,xn,yn] 格式重新排列，返回重排后的数组。
     */
    public class Class1470
    {
        public int[] Shuffle(int[] nums, int n)
        {
            IList<int> res = new List<int>();

            for (int i = 0; i < n; i++)
            {
                res.Add(nums[i]);
                res.Add(nums[i + n]);
            }
            return res.ToArray();
        }
    }
}
