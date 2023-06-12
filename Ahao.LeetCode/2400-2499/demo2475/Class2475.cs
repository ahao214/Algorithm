using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2400_2499.demo2475
{
    public class Class2475
    {
        public int UnequalTriplets(int[] nums)
        {
            int res = 0;
            int n = nums.Length;
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    for (int k = j + 1; k < n; k++)
                    {
                        if (nums[i] != nums[j] && nums[j] != nums[k] && nums[i] != nums[k])
                        {
                            res++;
                        }
                    }
                }
            }
            return res;
        }

    }
}
