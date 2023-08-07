using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1700_1799.demo1749
{
    internal class Class1749
    {
        public int MaxAbsoluteSum(int[] nums)
        {
            int preMax = 0;
            int preMin = 0;
            int prefix = 0;
            foreach (var item in nums)
            {
                prefix += item;
                preMax = Math.Max(preMax, prefix);
                preMin = Math.Min(preMin, prefix);
            }
            return preMax - preMin;
        }
    }
}
