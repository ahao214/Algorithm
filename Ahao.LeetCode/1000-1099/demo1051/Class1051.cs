using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1000_1099.demo1051
{
    public class Class1051
    {
        public int HeightChecker(int[] heights)
        {
            int n = heights.Length, ans = 0;
            int[] expected = new int[n];
            Array.Copy(heights, 0, expected, 0, n);
            Array.Sort(expected);
            for (int i = 0; i < n; ++i)
            {
                if (heights[i] != expected[i])
                {
                    ++ans;
                }
            }
            return ans;
        }
    }
}
