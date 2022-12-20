using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1700_1799.demo1760
{
    public class Class1760
    {
        public int MinimumSize(int[] nums, int maxOperations)
        {
            int left = 1, right = nums.Max();
            int ans = 0;
            while (left <= right)
            {
                int y = (left + right) / 2;
                long ops = 0;
                foreach (int x in nums)
                {
                    ops += (x - 1) / y;
                }
                if (ops <= maxOperations)
                {
                    ans = y;
                    right = y - 1;
                }
                else
                {
                    left = y + 1;
                }
            }
            return ans;
        }
    }
}
