using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1700_1799.demo1764
{
    public class Class1764
    {
        public bool CanChoose(int[][] groups, int[] nums)
        {
            int i = 0;
            for (int k = 0; k < nums.Length && i < groups.Length;)
            {
                if (Check(groups[i], nums, k))
                {
                    k += groups[i].Length;
                    i++;
                }
                else
                {
                    k++;
                }
            }
            return i == groups.Length;
        }

        public bool Check(int[] g, int[] nums, int k)
        {
            if (k + g.Length > nums.Length)
            {
                return false;
            }
            for (int j = 0; j < g.Length; j++)
            {
                if (g[j] != nums[k + j])
                {
                    return false;
                }
            }
            return true;
        }
    }
}
