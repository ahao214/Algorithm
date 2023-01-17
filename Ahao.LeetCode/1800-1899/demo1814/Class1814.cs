using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ahao.LeetCode._1800_1899.demo1814
{
    public class Class1814
    {
        public int CountNicePairs(int[] nums)
        {
            const int MOD = 1000000007;
            int res = 0;
            IDictionary<int, int> h = new Dictionary<int, int>();
            foreach (int i in nums)
            {
                int temp = i, j = 0;
                while (temp > 0)
                {
                    j = j * 10 + temp % 10;
                    temp /= 10;
                }
                h.TryAdd(i - j, 0);
                res = (res + h[i - j]) % MOD;
                h[i - j]++;
            }
            return res;
        }
    }
}
