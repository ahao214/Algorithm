using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo5990
{
    /*
     5990.找出数组中的所有孤独数字
    给你一个整数数组 nums 。如果数字 x 在数组中仅出现 一次 ，且没有 相邻 数字（即，x + 1 和 x - 1）出现在数组中，则认为数字 x 是 孤独数字 。

返回 nums 中的 所有 孤独数字。你可以按 任何顺序 返回答案。
     */
    public class Class5990
    {
        public IList<int> FindLonely(int[] nums)
        {
            IList<int> lst = new List<int>();
            Array.Sort(nums);
            lst.Add(nums[0]);
            for (int i = 1; i <= nums.Length - 1; i++)
            {
                if (nums[i] != nums[i - 1] + 1 && nums[i] != nums[i - 1])
                {
                    lst.Add(nums[i]);
                }
                else
                {
                    lst.Remove(nums[i - 1]);
                }
            }
            return lst;
        }
    }
}
