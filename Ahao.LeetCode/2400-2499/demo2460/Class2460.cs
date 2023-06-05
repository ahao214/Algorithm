using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2400_2499.demo2460
{
    public class Class2460
    {
        public int[] ApplyOperations(int[] nums)
        {
            int n = nums.Length;
            int[] res = new int[n];
            for (int i = 0, j = 0; i < n; i++)
            {
                if (i + 1 < n && nums[i] == nums[i + 1])
                {
                    nums[i] *= 2;
                    nums[i + 1] = 0;
                }
                if (nums[i] != 0)
                {
                    res[j] = nums[i];
                    j++;
                }
            }
            return res;
        }


    }
}
