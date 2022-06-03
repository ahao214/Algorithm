using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._0800_0899.demo829
{
    public class Class829
    {
        public int ConsecutiveNumbersSum(int n)
        {
            int ans = 0;
            int bound = 2 * n;
            for (int k = 1; k * (k + 1) <= bound; k++)
            {
                if (IsKConsecutive(n, k))
                {
                    ans++;
                }
            }
            return ans;
        }

        public bool IsKConsecutive(int n, int k)
        {
            if (k % 2 == 1)
            {
                return n % k == 0;
            }
            else
            {
                return n % k != 0 && 2 * n % k == 0;
            }
        }

    }
}
