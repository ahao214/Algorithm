using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._2200_2299.demo2283
{
    public class Class2283
    {
        public bool DigitCount(string num)
        {
            IDictionary<int, int> h = new Dictionary<int, int>();
            int n = num.Length;
            for (int i = 0; i < n; i++)
            {
                int digit = num[i] - '0';
                h.TryAdd(digit, 0);
                h[digit]++;
            }
            for (int i = 0; i < n; i++)
            {
                int v = num[i] - '0';
                h.TryAdd(i, 0);
                if (h[i] != v)
                {
                    return false;
                }
            }
            return true;
        }
    }
}
