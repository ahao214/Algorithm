using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1700_1799.demo1753
{
    public class Class1753
    {
        public int MaximumScore(int a, int b, int c)
        {
            int sum = a + b + c;
            int maxVal = Math.Max(Math.Max(a, b), c);
            return Math.Min(sum - maxVal, sum / 2);
        }

    }
}
