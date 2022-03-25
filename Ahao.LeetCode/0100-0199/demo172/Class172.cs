using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0100_0199.demo172
{
    public class Class172
    {
        public int TrailingZeroes(int n)
        {
            int ans = 0;
            for (int i = 5; i <= n; i += 5)
            {
                for (int x = i; x % 5 == 0; x /= 5)
                {
                    ++ans;
                }
            }
            return ans;
        }

        public int TrailingZeroes2(int n)
        {
            int ans = 0;
            while (n != 0)
            {
                n /= 5;
                ans += n;
            }
            return ans;
        }
    }
}
