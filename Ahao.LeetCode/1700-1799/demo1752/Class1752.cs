using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1700_1799.demo1752
{
    public class Class1752
    {
        public bool Check(int[] nums)
        {
            //统计后面的值小于前面的值的个数
            int count = 0;
            for (int i = 1; i < nums.Length; i++)
            {
                if (nums[i] < nums[i - 1])
                {
                    count++;
                }
            }

            if (count == 0 || (count == 1 && nums[0] >= nums[nums.Length - 1]))
                return true;
            return false;
        }

    }
}
