using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1600_1699.demo1663
{
    public class Class1663
    {
        public string GetSmallestString(int n, int k)
        {
            StringBuilder ans = new StringBuilder();
            for (int i = 1; i <= n; i++)
            {
                int lower = Math.Max(1, k - (n - i) * 26);
                k -= lower;
                ans.Append((char)('a' + lower - 1));
            }
            return ans.ToString();
        }


    }
}
