using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo334
{
    public class Class334
    {
        public bool IncreasingTriplet(int[] nums)
        {
            int len = nums.Length;
            if (len < 3)
            {
                return false;
            }
            int first = nums[0];
            int second = int.MaxValue;
            for (int i = 1; i < len; i++)
            {
                int tmp = nums[i];
                if (tmp > second)
                {
                    return true;
                }
                else if (tmp > first)
                {
                    second = tmp;
                }
                else
                {
                    first = tmp;
                }
            }
            return false;
        }
    }
}
