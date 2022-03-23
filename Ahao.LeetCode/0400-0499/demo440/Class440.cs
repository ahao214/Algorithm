using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0400_0499.demo440
{
    public class Class440
    {
        public int FindKthNumber(int n, int k)
        {
            int curr = 1;
            k--;
            while (k > 0)
            {
                int steps = GetSteps(curr, n);
                if (steps <= k)
                {
                    k -= steps;
                    curr++;
                }
                else
                {
                    curr = curr * 10;
                    k--;
                }
            }
            return curr;
        }

        public int GetSteps(int curr, int n)
        {
            long steps = 0;
            long first = curr;
            long last = curr;
            while (first <= n)
            {
                steps += Math.Min(last, n) - first + 1;
                first = first * 10;
                last = last * 10 + 9;
            }
            return (int)steps;
        }
    }
}
