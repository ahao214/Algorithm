using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1900_1999.demo1979
{
    public class Class1979
    {
        public int FindGCD(int[] nums)
        {
            int maxValue = int.MinValue;
            int minValue = int.MaxValue;
            foreach (var item in nums)
            {
                maxValue = Math.Max(item, maxValue);
                minValue = Math.Min(item, minValue);
            }
            return gcd(maxValue, minValue);
        }

        public int gcd(int a, int b)
        {
            return b == 0 ? a : gcd(b, a % b);
        }

    }
}
