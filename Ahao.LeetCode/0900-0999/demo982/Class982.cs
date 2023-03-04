using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0900_0999.demo982
{
    public class Class982
    {
        public int CountTriplets(int[] nums)
        {
            int res = 0;
            int n = nums.Length;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    for (int k = 0; k < n; k++)
                    {
                        if ((nums[i] & nums[j] & nums[k]) == 0)
                            res++;
                    }
                }
            }
            return res;
        }
    }
}
