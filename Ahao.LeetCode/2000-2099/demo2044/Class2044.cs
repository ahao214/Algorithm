using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode.Medium.demo2044
{
    public class Class2044
    {
        public int CountMaxOrSubsets(int[] nums)
        {
            int maxOr = 0, cnt = 0;
            for (int i = 0; i < 1 << nums.Length; i++)
            {
                int orVal = 0;
                for (int j = 0; j < nums.Length; j++)
                {
                    if (((i >> j) & 1) == 1)
                    {
                        orVal |= nums[j];
                    }
                }
                if (orVal > maxOr)
                {
                    maxOr = orVal;
                    cnt = 1;
                }
                else if (orVal == maxOr)
                {
                    cnt++;
                }
            }
            return cnt;
        }
    }
}
