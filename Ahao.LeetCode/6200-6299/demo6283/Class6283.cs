using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._6200_6299.demo6283
{
    public class Class6283
    {
        public int MaximumCount(int[] nums)
        {
            int positiveCount = 0;
            int negativeCount = 0;
            for (int i = 0; i < nums.Length; i++)
            {
                if (nums[i] > 0)
                {
                    positiveCount++;
                }
                if (nums[i] < 0)
                {
                    negativeCount++;
                }
            }
            return Math.Max(positiveCount, negativeCount);
        }
    }
}
