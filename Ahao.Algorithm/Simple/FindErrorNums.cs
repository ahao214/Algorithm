using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.Algorithm.Simple
{
    /// <summary>
    /// 645. 错误的集合
    /// </summary>
    public class FindErrorNums
    {
        public int[] Method(int[] nums)
        {
            Array.Sort(nums);
            int[] newNums = new int[2];
            int pre = 0;
            for (int i = 0; i < nums.Length; i++)
            {
                int cur = nums[i];
                if (pre == cur)
                {
                    newNums[0] = pre;
                }
                else if (cur - pre > 1)
                {
                    newNums[1] = pre + 1;
                }
                pre = cur;
            }
            if (nums[nums.Length - 1] != nums.Length)
            {
                newNums[1] = nums.Length;
            }
            return newNums;
        }

    }
}
