using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2200_2299.demo2216
{
    public class Class2216
    {
        public int MinDeletion(int[] nums)
        {
            int n = nums.Length;
            int ans = 0;
            bool check = true;
            for (int i = 0; i + 1 < n; ++i)
            {
                if (nums[i] == nums[i + 1] && check)
                {
                    ++ans;
                }
                else
                {
                    check = !check;
                }
            }
            if ((n - ans) % 2 != 0)
            {
                ++ans;
            }
            return ans;
        }

    }
}
